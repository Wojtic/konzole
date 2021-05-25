#include <stdint.h>

namespace menu
{
  int activePosition = 0;

  void setup()
  {
  }

  void loop()
  {
  }

  void drawBackground()
  {
    for (int i = 0; i < 240; i++)
    {
      tft.drawHLine(0, i, 320, /* gradient od modré do zelené */);
    }
    tft.fillRoundRect(0, 0, 320, 20, 30, /* bílá */);
  }

  void drawIcon(int x, int y, color_t col[], uint8_t icon[])
  {
    for (int dy = 0; dy < 32; dy++)
    {
    }
  }

  void drawItem(int position, uint8_t icon[], char text[], color_t colors[])
  {
    const int width = 60;
    const int border = 5;

    int x = (position % 3) * 80 + 20;
    int y = position / 3 * 80 + 20;
    int col = (position == activePosition) ? /* barva při vybrání */: /* základní barva */;
    int text = icon[3];

    tft.fillRect(x, y, width, width, /* černá */);
    tft.fillRect(x + border, y + border, width - 2 * border, width - 2 * border, col);

    drawIcon(x + 14, y + 6, colors, icon);
  }
}
