//========================================================================
//  This software is free: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License Version 3,
//  as published by the Free Software Foundation.
//
//  This software is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  Version 3 in the file COPYING that came with this distribution.
//  If not, see <http://www.gnu.org/licenses/>.
//========================================================================
/*!
  \file    plugin_colorthreshold.cpp
  \brief   C++ Implementation: plugin_colorthreshold
  \author  Stefan Zickler, 2008
*/
//========================================================================
#include "plugin_colorthreshold.h"

PluginColorThreshold::PluginColorThreshold(FrameBuffer * _buffer, YUVLUT * _lut)
 : VisionPlugin(_buffer)
{
  lut=_lut;
}


PluginColorThreshold::~PluginColorThreshold()
{
}



ProcessResult PluginColorThreshold::process(FrameData * data, RenderOptions * options) {
  (void)options;
  
  Image<raw8> * img_thresholded;
  
  if ((img_thresholded=(Image<raw8> *)data->map.get("cmv_threshold")) == 0) {
    img_thresholded=(Image<raw8> *)data->map.insert("cmv_threshold",new Image<raw8>());
  }

  if (data->video.getColorFormat()==COLOR_YUV422_UYVY) {
    //make sure image is allocated:
    img_thresholded->allocate(data->video.getWidth(),data->video.getHeight());
    //directly apply YUV lut:
    CMVisionThreshold::thresholdImageYUV422_UYVY(img_thresholded,&(data->video),lut);
  } else if (data->video.getColorFormat()==COLOR_YUV444) {
    //make sure image is allocated:
    img_thresholded->allocate(data->video.getWidth(),data->video.getHeight());
    //directly apply YUV lut:
    CMVisionThreshold::thresholdImageYUV444(img_thresholded,&(data->video),lut);    
  } else if (data->video.getColorFormat()==COLOR_RGB8) {
    //FIXME: check for changes in YUV LUT....if changed...copy things to RGB lut...
    printf("WARNING: Color thresholding of RGB8 is not yet implemented...for now, use YUV422 (UYVY) or YUV444 instead!\n");
  } else {
    fprintf(stderr,"ColorThresholding needs YUV422, YUV444, or RGB8 as input image, but found: %s\n",Colors::colorFormatToString(data->video.getColorFormat()).c_str());
    return ProcessingFailed;
  }
  
  return ProcessingOk;
}

VarList * PluginColorThreshold::getSettings() {
  return 0;
}

string PluginColorThreshold::getName() {
  return "Segmentation";
}