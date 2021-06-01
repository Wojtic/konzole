from PIL import Image
import math
im = Image.open(
    r"C:\Users\vojta\Documents\programovani\arduino\konzole\obrazky\ikony\7.png")
pic = im.load()

colors = []
icon = []

for i in range(32):
    count = 0
    for j in range(31):
        if pic[j, i] not in colors:
            colors.append(pic[j, i])
        if pic[j, i] == pic[j + 1, i]:
            count += 1
        else:
            icon.append(colors.index(pic[j, i]) * 32 + count)
            count = 0
    icon.append(colors.index(pic[31, i]) * 32 + count)

final_colors = []

for color in colors:
    num_color = (round(math.floor(color[0]/8)) << 11) + (
        round(math.floor(color[1]/4)) << 5) + round(math.floor(color[2]/8))
    final_colors.append(num_color)
print(icon, final_colors)

#iconArr = [ [None]*32 for i in range(32)]
# for i in range(32):
#    for j in range(32):
#        if pic[i, j] not in colors: colors.append(pic[i ,j])
#        iconArr[i][j] = colors.index(pic[i, j])
#
# for i in range(32):
#    count = 0
#    for j in range(31):
#        if iconArr[i][j] == iconArr[i][j+1]:
#            count += 1
#        else:
#            icon.append(iconArr[i][j] * 32 + count)
#            count = 0
#    icon.append(iconArr[i][j] * 32 + count)
