#ifndef COLORGEN_H
#define COLORGEN_H

#include <QVector>
#include <QColor>

class ColorGen
{
    QVector<QColor> used;
    ulong limit;

public:
    ColorGen(ulong lim);

    QColor operator()()
    {
        unsigned sz = used.size();
        while (sz < limit)
        {
            QColor clr(qrand() % 256, qrand() % 256, qrand() % 256);
            if (!used.contains(clr))
            {
                used.append(clr);
                return clr;
            }
        }

        used.clear();
        return QColor();
    }
};

#endif // COLORGEN_H
