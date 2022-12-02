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

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            pygame.display.quit()
            pygame.quit()
            sys.exit()
    dt = clock.tick(24) / 1000.0
#============================================================================

    x = a * sin(t) + vx
    y = b * cos(t) + vy
    t += 0.1
    t %= 500
    a += 0.1
    b += 0.1


#============================================================================
    screen.fill((0, 0, 0))
    pixels.append((x, y))
    for pix in pixels:
        add_pixel(pix[0], pix[1])
    pygame.draw.circle(screen, RED, (int(x), int(y)), 20)
    pygame.display.flip()
