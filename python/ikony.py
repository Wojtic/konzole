from PIL import Image
im = Image.open(
    r"C:\Users\vojta\Documents\programovani\arduino\konzole\obrazky\ikony\6.png")
pic = im.load()

colors = []
icon = []

for i in range(32):
    count = 0
    for j in range(31):
        if pic[i, j] not in colors:
            colors.append(pic[i, j])
        if pic[i, j] == pic[i, j + 1]:
            count += 1
        else:
            icon.append(colors.index(pic[i, j]) * 32 + count)
            count = 0
    icon.append(colors.index(pic[i, 31]) * 32 + count)

print(icon, colors)

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
