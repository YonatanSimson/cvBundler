/*
 *  Copyright (c) 2015  Sergio Garrido (sgarrido2011 (at) gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

/* cvbundler.h */
/* OpenCV Wrapper for Bundler */

#ifndef __cvbundler_h__
#define __cvbundler_h__

#include <vector>
#include <string>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

namespace cvbundler {

typedef vector<Point2f> KeyPointList;
typedef vector< pair<Point2f, Point2f> > MatchList;
typedef vector< pair<int, int> > MatchIndexList;

class cvbundler {
public:
    cvbundler() : _fixedIntrinsic(false) {};

    void setCameraParams(const Mat &camMatrix, const Mat &distCoeffs){};
    void setCameraParams(const vector<Mat> &camMatrix, const vector<Mat> &distCoeffs){};

    void doStructureFromMotion(const vector<Mat> &images, const vector< KeyPointList > &keypoints,
                               const vector< vector< MatchIndexList > > &matchesIndexes);
//    void doStructureFromMotion(const vector< KeyPointList > &keypoints,
//                               const vector< vector< MatchList > > &matches){};

private:
    vector<Mat> _images;
    vector< KeyPointList > _keypoints;
    vector< vector< MatchList > > _matches;
    vector<Mat> _camMatrix, _distCoeffs;
    bool _fixedIntrinsic;
    string _matchesFilename;

    static void _writeImagesFiles(string imgListFilename, string imageBasename, const vector<Mat> &images);
    static void _writeKeypointsFiles(string basename, const vector< KeyPointList > &keypoints);
    static void _writeMatchesFile(string matchesFilename, const vector< vector< MatchIndexList > > &matchesIndexes);
    void _writeOptionsFile(string optionsFilename);
//    void _writeIntrinsicFile(){};

    static void _getargcargv(string imgListFilename, string optionsFilename, int &argc, char** &argv);




};

}

#endif
