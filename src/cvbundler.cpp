#include "cvbundler.h"

#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include "BundlerApp.h"

namespace cvbundler {

void cvbundler::doStructureFromMotion(const vector<Mat> &images, const vector< KeyPointList > &keypoints,
                                      const vector< vector< MatchIndexList > > &matchesIndexes)
{
    CV_Assert(images.size() >= 2);
    CV_Assert(images.size() == keypoints.size());
    CV_Assert(images.size() == matchesIndexes.size());


    _writeImagesFiles("imageList", "img", images);

    _writeKeypointsFiles("img", keypoints);

    _matchesFilename = "matches.init.txt";
    _writeMatchesFile(_matchesFilename, matchesIndexes);

    _writeOptionsFile("options.txt");

////    if(_fixedIntrinsic)
////        _writeIntrinsicFile();

    char** argv;
    int argc;
    _getargcargv("imageList", "./options.txt", argc, argv);

    BundlerApp* bundler_app = new BundlerApp();
    bundler_app->argc = argc;
    bundler_app->argv = argv;

    std::cout << argv[0] << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
    std::cout << argv[3] << std::endl;

    bundler_app->OnInit();


//    char *imageList;
//    bool load_file = false;
//    if (argc >= 2) {
//    imageList = argv[1];
//    load_file = true;
//    } else {
//    PrintUsage();
//    exit(0);
//    }

//    ProcessOptions(argc - 1, argv + 1);

//    if (m_use_intrinsics && m_estimate_distortion) {
//        printf("Error: --intrinsics and --estimate_distortion "
//               "are incompatible\n");
//        exit(1);
//    }

//    if (m_fixed_focal_length && m_estimate_distortion) {
//        printf("Error: --fixed_focal_length and --estimate_distortion "
//               "are currently incompatible\n");
//        exit(1);
//    }

//    fflush(stdout);
//    if (load_file) {
//    FILE *f = fopen(imageList, "r");

//    if (f == NULL) {
//        printf("[BundlerApp::OnInit] Error opening file %s for reading\n",
//           imageList);
//        exit(1);
//    }

//        LoadImageNamesFromFile(f);

//    int num_images = GetNumImages();

//    fclose(f);
//    }

//    if (m_ignore_file != NULL) {
//        printf("[BundlerApp::OnInit] Reading ignore file...\n");
//        ReadIgnoreFile();
//    }

//    if (m_ignore_file != NULL) {
//        printf("[BundlerApp::OnInit] Reading ignore file...\n");
//        ReadIgnoreFile();
//    }

//    /* Do bundle adjustment (or read from file if provided) */
//    // ParseCommand("UndistortAll", NULL);
//    if (m_bundle_provided) {
//        printf("[BundlerApp::OnInit] Reading bundle file...\n");
//        ReadBundleFile(m_bundle_file);

//        if (m_bundle_version < 0.3) {
//            printf("[BundlerApp::OnInit] Reflecting scene...\n");
//            FixReflectionBug();
//        }

//        // AutoTagImages();

//        if (m_compress_list) {
//            // ParseCommand("UndistortAll", NULL);
//            OutputCompressed();
//            return 0;
//        }

//        if (m_reposition_scene) {
//            double center[3], R[9], scale;
//            RepositionScene(center, R, scale);
//            OutputCompressed("reposition");
//            return 0;
//        }

//        if (m_prune_bad_points) {
//            SetupImagePoints(3);
//            RemoveBadImages(24);
//            PruneBadPoints();
//            OutputCompressed("pruned");
//            return 0;
//        }

//        if (m_scale_focal != 1.0) {
//            ScaleFocalLengths(m_scale_focal);
//            return 0;
//        }

//        if (m_scale_focal_file != NULL) {
//            ScaleFocalLengths(m_scale_focal_file);
//            return 0;
//        }

//        if (m_rotate_cameras_file != NULL) {
//            RotateCameras(m_rotate_cameras_file);
//        }



//        if (m_track_file != NULL) {
//            // ReadGeometricConstraints("constraints.txt");
//            CreateTracksFromPoints();
//            WriteTracks(m_track_file);
//        }

//        if (m_zero_distortion_params) {
//            ZeroDistortionParams();
//            OutputCompressed("nord");
//            return 0;
//        }



//        if (m_output_relposes) {
//            double center[3], R[9], scale;
//            RepositionScene(center, R, scale);
//            RepositionScene(center, R, scale);
//            // OutputRelativePoses2D(m_output_relposes_file);
//            OutputRelativePoses3D(m_output_relposes_file);
//            return 0;
//        }

//        if (m_compute_covariance) {
//            ComputeCameraCovariance();
//            return 0;
//        }

//      #define MIN_POINT_VIEWS 3 // 0 // 2
//        if (!m_run_bundle) {
//            SetMatchesFromPoints(MIN_POINT_VIEWS);
//            // WriteMatchTableDrew(".final");

//            printf("[BundlerApp::OnInit] "
//                   "Setting up image points and lines...\n");
//            SetupImagePoints(/*2*/ MIN_POINT_VIEWS);
//            RemoveBadImages(6);

//            if (m_point_constraint_file != NULL) {
//                printf("[BundlerApp::OnInit] Reading point constraints...\n");
//                m_use_point_constraints = true;
//                ReadPointConstraints();
//            }

//            printf("[BundlerApp::OnInit] Scaling world...\n");

//            printf("[BundlerApp::OnInit] Computing camera orientations...\n");
//            ComputeImageRotations();

//            // printf("[BundlerApp::OnInit] Computing ground plane...\n");
//            // FindGroundPlane();

//            double center[3], R[9], scale;
//            RepositionScene(center, R, scale);

//        }

//        if (m_add_image_file != NULL) {
//            printf("[BundlerApp::OnInit] Adding additional images...\n");
//            FILE *f = fopen(m_add_image_file, "r");

//            if (f == NULL) {
//                printf("[BundlerApp::OnInit] Error opening file %s for "
//                       "reading\n",
//                       m_add_image_file);
//            } else {

//                BundleImagesFromFile(f);

//                /* Write the output */
//                OutputCompressed("added");

//                if (m_bundle_version < 0.3)
//                    FixReflectionBug();

//                // RunSFMWithNewImages(4);



//                fclose(f);
//            }
//        }

//    }

//    if (m_run_bundle) {

//        if (!m_fast_bundle)
//            BundleAdjust();
//        else
//            BundleAdjustFast();

//        if (m_bundle_version < 0.3)
//            FixReflectionBug();

//    exit(0);

//    }



//    return true;
}




void cvbundler::_writeImagesFiles(string imgListFilename, string imageBasename, const vector<Mat> &images) {
    ofstream imgListFile;
    imgListFile.open(imgListFilename.c_str());
    for(int i=0; i<images.size(); i++) {
        stringstream imgName;
        imgName << imageBasename << i << ".jpg";
        imwrite(imgName.str(), images[i]);

        imgListFile << "./" << imgName.str() << "\n";
    }
    imgListFile.close();
}

void cvbundler::_writeKeypointsFiles(string basename, const vector< KeyPointList > &keypoints) {
    for(int i=0; i<keypoints.size(); i++) {
        stringstream filename;
        filename << basename << i << ".key";
        ofstream keyfile;
        keyfile.open(filename.str().c_str());
        keyfile << keypoints[i].size() << " 128\n";
        for(int k=0; k<keypoints[i].size(); k++) {
            keyfile << keypoints[i][k].x << " " << keypoints[i][k].y << " 1.0 1.0\n";
            for(int k=0; k<6; k++) keyfile << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n";
            keyfile << "1 1 1 1 1 1 1 1\n";
        }
        keyfile.close();
    }
}

void cvbundler::_writeMatchesFile(string matchesFilename, const vector< vector< MatchIndexList > > &matchesIndexes) {
    ofstream matchesfile;
    matchesfile.open(matchesFilename.c_str());
    for(int i=0; i<matchesIndexes.size()-1; i++) {
        for(int j=i+1; j<matchesIndexes.size(); j++) {
            if(matchesIndexes[i][j].size() == 0) continue;
            matchesfile << i << " " << j << "\n";
            matchesfile << matchesIndexes[i][j].size() << "\n";
            for(int k=0; k<matchesIndexes[i][j].size(); k++)
                matchesfile << matchesIndexes[i][j][k].first << " " << matchesIndexes[i][j][k].second << "\n";
        }
    }
    matchesfile.close();
}


void cvbundler::_writeOptionsFile(string optionsFilename) {
    ofstream optionsfile;
    optionsfile.open(optionsFilename.c_str());
    optionsfile << "--run_bundle\n";
    optionsfile << "--use_focal_estimate\n";
    optionsfile << "--constrain_focal\n";
    optionsfile << "--estimate_distortion\n";
    optionsfile << "--match_table " << _matchesFilename << "\n";
    optionsfile << "--variable_focal_length\n";
    optionsfile << "--output bundle.out\n";
    optionsfile << "--constrain_focal_weight 0.0001\n";
    optionsfile.close();
}


void cvbundler::_getargcargv(string imgListFilename, string optionsFilename, int &argc, char** &argv) {
    argv = new char* [4];

    argv[0] = strdup("bundler");
    argv[1] = strdup(imgListFilename.c_str());
    argv[2] = strdup("--options_file");
    argv[3] = strdup(optionsFilename.c_str());
//    argv[2] = strdup("--run_bundle");
//    argv[3] = strdup("--use_focal_estimate");
//    argv[4] = strdup("--constrain_focal");
//    argv[5] = strdup("--estimate_distortion");
//    argv[6] = strdup("--match_table");
//    argv[7] = strdup("matches.init.txt");
//    argv[8] = strdup("--output");
//    argv[9] = strdup("bundle.out");
//    argv[10] = strdup("--constrain_focal_weight");
//    argv[11] = strdup("0.0001");

    argc = 4;
}



}
