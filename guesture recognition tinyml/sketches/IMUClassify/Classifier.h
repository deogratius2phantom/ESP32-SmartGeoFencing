#ifndef UUID2848463252168
#define UUID2848463252168

/**
  * RandomForestClassifier(base_estimator=DecisionTreeClassifier(), bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=20, max_features=auto, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=20, n_jobs=None, num_outputs=4, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[4] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree10(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree11(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree12(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree13(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree14(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree15(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree16(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree17(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree18(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree19(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 4; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "walk";
                    
                        case 1:
                            return "walk1";
                    
                        case 2:
                            return "wave";
                    
                        case 3:
                            return "idle";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[101] <= 0.21204516291618347) {
                            
                                
                        *classIdx = 2;
                        *classScore = 37.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[6] <= 0.004550685407593846) {
                            
                                
                        *classIdx = 3;
                        *classScore = 38.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[141] <= 0.28080902993679047) {
                            
                                
                        if (x[117] <= 0.6927961111068726) {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 38.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[142] <= 0.4310912489891052) {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[140] <= 0.9492003619670868) {
                            
                                
                        *classIdx = 1;
                        *classScore = 37.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[139] <= 0.0075547378219198436) {
                            
                                
                        *classIdx = 3;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[20] <= 0.6801405847072601) {
                            
                                
                        if (x[143] <= 0.28080902993679047) {
                            
                                
                        *classIdx = 0;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[124] <= 0.38614341616630554) {
                            
                                
                        *classIdx = 0;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[140] <= 0.9515522122383118) {
                            
                                
                        *classIdx = 1;
                        *classScore = 41.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[14] <= 41.0) {
                            
                                
                        if (x[22] <= 0.6801405847072601) {
                            
                                
                        if (x[109] <= 0.0017816462204791605) {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[40] <= 0.47427184879779816) {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 39.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[109] <= 0.030273946933448315) {
                            
                                
                        if (x[131] <= 30.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 30.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[45] <= 0.25501199811697006) {
                            
                                
                        if (x[3] <= 0.24365004152059555) {
                            
                                
                        *classIdx = 0;
                        *classScore = 41.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 41.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 33.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[125] <= 0.2320350557565689) {
                            
                                
                        if (x[91] <= 23.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[143] <= 0.28080902993679047) {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[109] <= 0.0023154973750934005) {
                            
                                
                        *classIdx = 1;
                        *classScore = 37.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[81] <= 0.32332563400268555) {
                            
                                
                        *classIdx = 1;
                        *classScore = 37.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 39.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] <= 0.013464898976963013) {
                            
                                
                        *classIdx = 3;
                        *classScore = 43.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[26] <= 0.011094106826931238) {
                            
                                
                        if (x[101] <= 0.4294228255748749) {
                            
                                
                        if (x[79] <= 0.0992155522108078) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[46] <= 0.011846073903143406) {
                            
                                
                        *classIdx = 0;
                        *classScore = 35.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[149] <= 0.003470840980298817) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[12] <= 97.0) {
                            
                                
                        *classIdx = 3;
                        *classScore = 43.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[48] <= 0.049549708142876625) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[91] <= 22.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 35.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[120] <= 0.6241043508052826) {
                            
                                
                        if (x[44] <= 0.5048660337924957) {
                            
                                
                        if (x[143] <= 0.1848541796207428) {
                            
                                
                        *classIdx = 0;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[112] <= 101.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[60] <= 0.6178546249866486) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 40.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 40.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[134] <= 57.0) {
                            
                                
                        if (x[108] <= 0.04296233505010605) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[120] <= 0.5125726461410522) {
                            
                                
                        *classIdx = 0;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[125] <= 0.22281669825315475) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 25.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 46.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[120] <= 0.6801405847072601) {
                            
                                
                        if (x[40] <= 0.5501618087291718) {
                            
                                
                        if (x[134] <= 65.5) {
                            
                                
                        if (x[139] <= 0.1362326703965664) {
                            
                                
                        if (x[48] <= 0.04239489324390888) {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 42.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 42.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 34.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[115] <= 39.0) {
                            
                                
                        if (x[25] <= 0.2394447699189186) {
                            
                                
                        if (x[118] <= 0.7254010438919067) {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[5] <= 0.352561853826046) {
                            
                                
                        *classIdx = 0;
                        *classScore = 35.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[0] <= 0.9515522122383118) {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 39.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #10
                 */
                void tree10(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[103] <= 0.21204516291618347) {
                            
                                
                        *classIdx = 2;
                        *classScore = 38.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[115] <= 36.0) {
                            
                                
                        if (x[40] <= 0.5458737909793854) {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 40.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #11
                 */
                void tree11(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[51] <= 18.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[99] <= 0.12821410968899727) {
                            
                                
                        if (x[68] <= 0.059890031814575195) {
                            
                                
                        *classIdx = 1;
                        *classScore = 41.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[115] <= 12.0) {
                            
                                
                        if (x[143] <= 0.4880056381225586) {
                            
                                
                        *classIdx = 0;
                        *classScore = 37.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 41.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 41.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 32.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #12
                 */
                void tree12(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[155] <= 57.0) {
                            
                                
                        if (x[139] <= 0.22865909337997437) {
                            
                                
                        if (x[1] <= 0.28080902993679047) {
                            
                                
                        *classIdx = 0;
                        *classScore = 28.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[101] <= 0.4187578558921814) {
                            
                                
                        if (x[28] <= 0.028974116779863834) {
                            
                                
                        *classIdx = 0;
                        *classScore = 28.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 34.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 46.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #13
                 */
                void tree13(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[121] <= 0.20657023042440414) {
                            
                                
                        *classIdx = 2;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[106] <= 0.002387594315223396) {
                            
                                
                        *classIdx = 3;
                        *classScore = 38.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[23] <= 0.35852372646331787) {
                            
                                
                        if (x[128] <= 0.017450226470828056) {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[43] <= 0.28131067752838135) {
                            
                                
                        if (x[52] <= 10.0) {
                            
                                
                        *classIdx = 2;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[103] <= 0.3933500498533249) {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 38.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 37.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #14
                 */
                void tree14(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[21] <= 0.44876301288604736) {
                            
                                
                        if (x[25] <= 0.23034334927797318) {
                            
                                
                        if (x[118] <= 0.7254010438919067) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] <= 0.3431326448917389) {
                            
                                
                        *classIdx = 0;
                        *classScore = 29.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[111] <= 63.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 29.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 36.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 45.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #15
                 */
                void tree15(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[106] <= 0.0023023230023682117) {
                            
                                
                        *classIdx = 3;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[139] <= 0.21543516591191292) {
                            
                                
                        if (x[144] <= 0.3801107257604599) {
                            
                                
                        *classIdx = 0;
                        *classScore = 34.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[23] <= 0.32972826063632965) {
                            
                                
                        *classIdx = 0;
                        *classScore = 34.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[131] <= 57.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[66] <= 0.028280040249228477) {
                            
                                
                        *classIdx = 0;
                        *classScore = 34.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #16
                 */
                void tree16(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[23] <= 0.2663241922855377) {
                            
                                
                        if (x[78] <= 7.864013910293579) {
                            
                                
                        *classIdx = 2;
                        *classScore = 38.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[114] <= 61.5) {
                            
                                
                        if (x[44] <= 0.5048660337924957) {
                            
                                
                        if (x[141] <= 0.24365004152059555) {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[9] <= 0.012733240146189928) {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #17
                 */
                void tree17(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[128] <= 0.10847704112529755) {
                            
                                
                        if (x[119] <= 0.08203671127557755) {
                            
                                
                        if (x[147] <= 2.1868887188247754e-05) {
                            
                                
                        *classIdx = 3;
                        *classScore = 30.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[88] <= 0.07220782898366451) {
                            
                                
                        *classIdx = 0;
                        *classScore = 40.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 35.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 38.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #18
                 */
                void tree18(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[131] <= 30.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 45.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[109] <= 0.002476649242453277) {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[108] <= 0.17071111872792244) {
                            
                                
                        if (x[41] <= 0.28131067752838135) {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 29.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #19
                 */
                void tree19(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[110] <= 21.5) {
                            
                                
                        *classIdx = 3;
                        *classScore = 43.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[120] <= 0.6801405847072601) {
                            
                                
                        if (x[144] <= 0.38262537121772766) {
                            
                                
                        *classIdx = 0;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[48] <= 0.04239489324390888) {
                            
                                
                        if (x[124] <= 0.37774278223514557) {
                            
                                
                        *classIdx = 0;
                        *classScore = 36.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 36.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }

                }
            
        


            
};



static RandomForestClassifier forest;


#endif