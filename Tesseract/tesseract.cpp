#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    //使用中文初始化tesseract-ocr，而不指定tessdata路径。
    if (api->Init(NULL, "chi_sim"/*"eng"*/)) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // 使用leptonica库打开输入图像。
    Pix* image = pixRead("test.png");
    api->SetImage(image);

    // 得到光学字符识别结果
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);


    // 销毁使用过的对象并释放内存。
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
