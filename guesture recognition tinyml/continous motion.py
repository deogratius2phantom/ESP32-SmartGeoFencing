from everywhereml.data import Dataset
from everywhereml.data.collect import SerialCollector
from everywhereml.preprocessing import Pipeline, MinMaxScaler, Window, SpectralFeatures
from everywhereml.sklearn.ensemble import RandomForestClassifier
sampling_frequency = 104
mean_gesture_duration_in_millis = 1000
window_length = sampling_frequency * mean_gesture_duration_in_millis // 1000
"""
Create a SerialCollector object.
Each data line is marked by the 'IMU:' string
Collect 30 seconds of data for each gesture
Replace the port with your own!

If a imu.csv file already exists, skip collection
"""

try:
    imu_dataset = Dataset.from_csv(
        'imu.csv', 
        name='ContinuousMotion', 
        target_name_column='target_name'
    )
    
except FileNotFoundError:
    imu_collector = SerialCollector(
        port='COM4', 
        baud=115200, 
        start_of_frame='IMU:', 
        feature_names=['AccelX', 'AccelY', 'AccelZ', 'GyroX', 'GyroY', 'GyroZ','Pitch','Roll'] #adding more data points could improve accuracy (magnetmeter);
    )
    imu_dataset = imu_collector.collect_many_classes(
        dataset_name='ContinuousMotion', 
        duration=60
    )
    
    # save dataset to file for later use
    imu_dataset.df.to_csv('imu.csv', index=False)



imu_pipeline = Pipeline(name='ContinousMotionPipeline', steps=[
    MinMaxScaler(),
    # shift can be an integer (number of samples) or a float (percent)
    Window(length=window_length, shift=0.3),
    # order can either be 1 (first-order features) or 2 (add second-order features)
    SpectralFeatures(order=2)
])
from pprint import pprint
pprint(imu_pipeline['SpectralFeatures'][0].feature_names)
imu_dataset.apply(imu_pipeline)
imu_dataset.describe()
imu_classifier = RandomForestClassifier(n_estimators=20, max_depth=20)
imu_train, imu_test = imu_dataset.split(test_size=0.3)
imu_classifier.fit(imu_train)

print('Score on test set: %.2f' % imu_classifier.score(imu_test))
"""
Port pipeline to C++
"""
print(imu_pipeline.to_arduino_file(
    'sketches/IMUClassify/Pipeline.h', 
    instance_name='pipeline'
))
"""
Port classifier to C++
"""
print(imu_classifier.to_arduino_file(
    'sketches/IMUClassify/Classifier.h', 
    instance_name='forest', 
    class_map=imu_dataset.class_map
))
