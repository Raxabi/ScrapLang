#ifndef POSITION_H
#define POSITION_H

namespace Scrap {
namespace Scan {

struct Position {
public:
    int pos;
    int line;
    int pos_line;

public:
    Position(int pos, int line, int pos_line);
};

} // namespace Scan
} // namespace Scrap

#endif // POSITION_H