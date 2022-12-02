import sys
import pygame
from math import sin, cos

pygame.init()

width = 500
height = 500
RED = (150, 10, 50)

screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('Fuko')
clock = pygame.time.Clock()

x0 = width / 2
y0 = height /2
vx = width / 2
vy = height /2
a = 50
b = 50
t = 0
omega = 90

def add_pixel(x, y):
    pygame.draw.line(screen, (255, 255, 255), (x,y), (x,y))
pixels = []

def xt(t, x0):
    print(9/20 * x0 * cos(22/99 * t))
    return 9/20 * x0 * cos(22/99 * t) + 11/20 * x0 * cos(18/99 * t)
def yt(t, x0):
    return -9/20 * x0 * sin(22/99 * t) + 11/20 * x0 * sin(18/99 * t)

running = True
stop = False
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            pygame.display.quit()
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                if not stop:
                    stop = True
                else:
                    stop = False
    if stop:
        continue
    dt = clock.tick(24) / 1000.0
#============================================================================

##    x = a * sin(t) + vx
##    y = b * cos(t) + vy
##    a += 0.1
##    b += 0.1
    x = xt(t, vx) + vx
    y = yt(t, vy) + vy

    t += 0.1
    t %= 500
    if t == 0:
        pixels = []


#============================================================================
    screen.fill((0, 0, 0))
    pixels.append((x, y))
    for pix in pixels:
        add_pixel(pix[0], pix[1])
    pygame.draw.circle(screen, RED, (int(x), int(y)), 20)
    pygame.display.flip()
