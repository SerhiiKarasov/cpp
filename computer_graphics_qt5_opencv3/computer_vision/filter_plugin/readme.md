#Borders
https://vovkos.github.io/doxyrest-showcase/opencv/sphinx_rtd_theme/enum_cv_BorderTypes.html
https://vovkos.github.io/doxyrest-showcase/opencv/sphinx_rtd_theme/page_tutorial_copyMakeBorder.html?highlight=bordertypes
copyMakeBorder( src, dst, top, bottom, left, right, borderType, value );
enum BorderTypes
{
    BORDER_CONSTANT    = 0,
    BORDER_REPLICATE   = 1,
    BORDER_REFLECT     = 2,
    BORDER_WRAP        = 3,
    BORDER_REFLECT_101 = 4,
    BORDER_TRANSPARENT = 5,
    BORDER_REFLECT101  = BORDER_REFLECT_101,
    BORDER_DEFAULT     = BORDER_REFLECT_101,
    BORDER_ISOLATED    = 16,
};

#Filters
https://vovkos.github.io/doxyrest-showcase/opencv/sphinx_rtd_theme/group_imgproc_filter.html?highlight=bilateralfilter
bilateralFilter - may be cartoonish(if sigmas are high)
blur, boxFilter, sqrBoxFilter, GaussianBlur, and medianBlur - filter for smoothing the picture. 
filter2D: This function can be used to apply a custom filter to an image. he one important parameter that you need to provide to this function is the kernel matrix. This function is very powerful and it can produce a lot of different results including the same result as the blur functions.
Laplacian, Scharr, Sobel, and spatialGradient: These functions deal with image derivatives. hese functions deal with image derivatives. Image derivatives are very important in computer vision since they can be used to detect regions with changes, or, better yet, significant changes (since that's one of the use cases of derivatives) in an image.
erode and dilate:for getting an erosion and dilation effect
morphologyEx: MORPH_ERODE, MORPH_DILATE, MORPH_OPEN(remove small artifacts, dilating an eroded image), MORPH_CLOSE(eroding a dilated and is useful for removing small disconnections in lines and so on), MORPH_GRADIENT(outline of an image, and it's the same as the difference of an eroded and dilated version of the same image), MORPH_TOPHAT(difference between an image and its opening morph. ), MORPH_BLACKHAT( difference between the closing of an image and the image itself)
