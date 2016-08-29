

#include <stdio.h>
//  /usr/include/linux/videodev2.h
//  /struct v4l2_format   //查找得到

//结构体 +  联合体 +  enum  枚举   

enum v4l2_buf_type {
    V4L2_BUF_TYPE_VIDEO_CAPTURE        = 1,
    V4L2_BUF_TYPE_VIDEO_OUTPUT         = 2,
    V4L2_BUF_TYPE_VIDEO_OVERLAY        = 3,
    V4L2_BUF_TYPE_VBI_CAPTURE          = 4,
    V4L2_BUF_TYPE_VBI_OUTPUT           = 5,
    V4L2_BUF_TYPE_SLICED_VBI_CAPTURE   = 6,
    V4L2_BUF_TYPE_SLICED_VBI_OUTPUT    = 7,
    V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY = 8,
    V4L2_BUF_TYPE_PRIVATE              = 0x80,
};
//多功能结构体  占用空间最小
struct v4l2_format {
    enum v4l2_buf_type type;
    union {
        struct v4l2_pix_format      pix;     /* V4L2_BUF_TYPE_VIDEO_CAPTURE */
        struct v4l2_window      win;     /* V4L2_BUF_TYPE_VIDEO_OVERLAY */
        struct v4l2_vbi_format      vbi;     /* V4L2_BUF_TYPE_VBI_CAPTURE */
        struct v4l2_sliced_vbi_format   sliced;/*V4L2_BUF_TYPE_SLICED_VBI_CAPTURE*/
		struct xxxxx  xx1 ; 	       /*  */
        __u8    raw_data[200];                   /* user-defined */
    } fmt;
};


int main(void)
{



	return 0 ; 
}
