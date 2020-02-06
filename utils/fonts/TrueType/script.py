from fontTools.ttLib import TTFont
from fontTools.pens.reportLabPen import ReportLabPen

from reportlab.lib import colors
from reportlab.graphics import renderPM
from reportlab.graphics.shapes import Group, Drawing, scale, Path

font = TTFont('KAPL.TTF')
gs = font.getGlyphSet()


w, h = 1000, 1000
    
for name in font.getGlyphNames():
    uid = font.getGlyphID(name)
    
    gly = gs[name]
    
    pen = ReportLabPen(gs, Path(fillColor=colors.red, strokeWidth=5))
    gly.draw(pen)


    # Everything is wrapped in a group to allow transformations.
    g = Group(pen.path)
    d = Drawing(w, h)
    d.add(g)
    renderPM.drawToFile(d, f'{uid}_{name}.png', fmt="PNG")

