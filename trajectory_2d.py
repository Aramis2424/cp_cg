import sys
import pygame
from math import sin, cos, sqrt

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

phi = 90
omega = 7.292e-5
omega_z = omega * sin(phi)
gl = 10 / 50
omega_0 = sqrt(gl)
_omega_ = sqrt(omega_0**2 + omega_z**2)
omega_minus = _omega_ - omega_z
omega_plus = _omega_ + omega_z

def x_new_1(t, x0):
    return x0*omega_minus/(2*_omega_) * cos(omega_plus*t) +\
           x0*omega_plus/(2*_omega_) * cos(omega_minus*t)
def y_new_1(t, x0):
    return -x0*omega_minus/(2*_omega_) * sin(omega_plus*t) +\
           x0*omega_plus/(2*_omega_) * sin(omega_minus*t)


def x_new_0(t, x0):
    return 9/20 * x0 * cos(22/99 * t) + 11/20 * x0 * cos(18/99 * t)
def y_new_0(t, x0):
    return -9/20 * x0 * sin(22/99 * t) + 11/20 * x0 * sin(18/99 * t)


def add_pixel(x, y):
    pygame.draw.line(screen, (255, 255, 255), (x,y), (x,y))
pixels = []


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
    x = x_new_1(t, vx) + vx
    y = y_new_1(t, vy) + vy

    t += 0.1
    t %= 5000
    if t == 0:
        pixels = []


#============================================================================
    screen.fill((0, 0, 0))
    pixels.append((x, y))
    for pix in pixels:
        add_pixel(pix[0], pix[1])
    pygame.draw.circle(screen, RED, (int(x), int(y)), 20)
    pygame.display.flip()
