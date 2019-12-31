#include "FreedesktopImageHint.h"

#include <QDBusMetaType>
#include <QImage>

int FreedesktopImageHint::imageHintID = qDBusRegisterMetaType<FreedesktopImageHint>();

FreedesktopImageHint::FreedesktopImageHint(const QImage &img)
{
    QImage image(img.convertToFormat(QImage::Format_ARGB32).rgbSwapped());
    imageData = QByteArray((char *)image.bits(), image.byteCount());
    width = image.width();
    height = image.height();
    rowstride = image.bytesPerLine();
    hasAlpha = image.hasAlphaChannel();
    channels = hasAlpha ? 4 : 3;
    bitsPerSample = image.depth() / channels;

}

QImage FreedesktopImageHint::toQImage() const
{
    return QImage((uchar *)imageData.data(), width, height, QImage::Format_ARGB32).rgbSwapped();
}

QDBusArgument &operator<<(QDBusArgument &a, const FreedesktopImageHint &i)
{
    a.beginStructure();
    a << i.width <<
      i.height <<
      i.rowstride <<
      i.hasAlpha <<
      i.bitsPerSample <<
      i.channels <<
      i.imageData;
    a.endStructure();
    return a;
}

const QDBusArgument &operator >>(const QDBusArgument &a,  FreedesktopImageHint &i)
{
    a.beginStructure();
    a >> i.width >>
      i.height >>
      i.rowstride >>
      i.hasAlpha >>
      i.bitsPerSample >>
      i.channels >>
      i.imageData;
    a.endStructure();
    return a;
}
