import os.path
import pygame
from random import randint, uniform, choice
import math
import matplotlib as mpl

vector = pygame.math.Vector2
gravity = vector(0, 0.3)
DISPLAY_WIDTH = DISPLAY_HEIGHT = 800

trail_colours = [(45, 45, 45), (60, 60, 60), (75, 75, 75), (125, 125, 125),
                 (150, 150, 150)]
dynamic_offset = 1
static_offset = 3

pygame.init()


# size=width,height=900,500
# screen=pygame.display.set_mode(size)

# pygame.display.set_mode((200,100),pygame.FULLSCREEN)
class Firework:
    def __init__(self):
        # 随机颜色
        self.colour = (randint(0, 255), randint(0, 255), randint(0, 255))
        self.colours = (
            (randint(0, 255), randint(0, 255), randint(0, 255)),
            (randint(0, 255), randint(0, 255), randint(0, 255)),
            (randint(0, 255), randint(0, 255), randint(0, 255)))
        self.firework = Particle(randint(0, DISPLAY_WIDTH), DISPLAY_HEIGHT,
                                 True,
                                 self.colour)  # Creates the firework particle
        self.exploded = False
        self.particles = []
        self.min_max_particles = vector(100, 225)

    def update(self, win):  # called every frame
        if not self.exploded:
            self.firework.apply_force(gravity)
            self.firework.move()
            for tf in self.firework.trails:
                tf.show(win)

            self.show(win)

            if self.firework.vel.y >= 0:
                self.exploded = True
                self.explode()
        else:
            for particle in self.particles:
                particle.apply_force(vector(gravity.x + uniform(-1, 1) / 20,
                                            gravity.y / 2 + (
                                                    randint(1, 8) / 100)))
                particle.move()
                for t in particle.trails:
                    t.show(win)
                particle.show(win)

    def explode(self):
        # amount 数量
        amount = randint(self.min_max_particles.x, self.min_max_particles.y)
        for i in range(amount):
            self.particles.append(
                Particle(self.firework.pos.x, self.firework.pos.y, False,
                         self.colours))

    def show(self, win):
        pygame.draw.circle(win, self.colour,
                           (int(self.firework.pos.x), int(self.firework.pos.y)),
                           self.firework.size)

    def remove(self):
        if self.exploded:
            for p in self.particles:
                if p.remove is True:
                    self.particles.remove(p)

            if len(self.particles) == 0:
                return True
            else:
                return False


class Particle:
    def __init__(self, x, y, firework, colour):
        self.firework = firework
        self.pos = vector(x, y)
        self.origin = vector(x, y)
        self.radius = 20
        self.remove = False
        self.explosion_radius = randint(5, 18)
        self.life = 0
        self.acc = vector(0, 0)
        # trail variables
        self.trails = []  # stores the particles trail objects
        self.prev_posx = [-10] * 10  # stores the 10 last positions
        self.prev_posy = [-10] * 10  # stores the 10 last positions

        if self.firework:
            self.vel = vector(0, -randint(17, 20))
            self.size = 5
            self.colour = colour
            for i in range(5):
                self.trails.append(Trail(i, self.size, True))
        else:
            self.vel = vector(uniform(-1, 1), uniform(-1, 1))
            self.vel.x *= randint(7, self.explosion_radius + 2)
            self.vel.y *= randint(7, self.explosion_radius + 2)
            # 向量
            self.size = randint(2, 4)
            self.colour = choice(colour)
            # 5 个 tails总计
            for i in range(5):
                self.trails.append(Trail(i, self.size, False))

    def apply_force(self, force):
        self.acc += force

    def move(self):
        if not self.firework:
            self.vel.x *= 0.8
            self.vel.y *= 0.8
        self.vel += self.acc
        self.pos += self.vel
        self.acc *= 0

        if self.life == 0 and not self.firework:  # check if particle is outside explosion radius
            distance = math.sqrt((self.pos.x - self.origin.x) ** 2 + (
                    self.pos.y - self.origin.y) ** 2)
            if distance > self.explosion_radius:
                self.remove = True

        self.decay()

        self.trail_update()

        self.life += 1

    def show(self, win):
        pygame.draw.circle(win,
                           (self.colour[0], self.colour[1], self.colour[2], 0),
                           (int(self.pos.x), int(self.pos.y)), self.size)

    def decay(self):  # random decay of the particles
        if 50 > self.life > 10:  # early stage their is a small chance of decay
            ran = randint(0, 30)
            if ran == 0:
                self.remove = True
        elif self.life > 50:
            ran = randint(0, 5)
            if ran == 0:
                self.remove = True

    def trail_update(self):
        self.prev_posx.pop()
        self.prev_posx.insert(0, int(self.pos.x))
        self.prev_posy.pop()
        self.prev_posy.insert(0, int(self.pos.y))

        for n, t in enumerate(self.trails):
            if t.dynamic:
                t.get_pos(self.prev_posx[n + dynamic_offset],
                          self.prev_posy[n + dynamic_offset])
            else:
                t.get_pos(self.prev_posx[n + static_offset],
                          self.prev_posy[n + static_offset])


class Trail:
    def __init__(self, n, size, dynamic):
        self.pos_in_line = n
        self.pos = vector(-10, -10)
        self.dynamic = dynamic

        if self.dynamic:
            self.colour = trail_colours[n]
            self.size = int(size - n / 2)
        else:
            self.colour = (255, 255, 200)
            self.size = size - 2
            if self.size < 0:
                self.size = 0

    def get_pos(self, x, y):
        self.pos = vector(x, y)

    def show(self, win):
        pygame.draw.circle(win, self.colour, (int(self.pos.x), int(self.pos.y)),
                           self.size)


def update(win, fireworks):
    for fw in fireworks:
        fw.update(win)
        if fw.remove():
            fireworks.remove(fw)

    pygame.display.update()


def main():
    pygame.init()
    pygame.font.init()
    screen_width, screen_height = 800, 600
    screen = pygame.display.set_mode((screen_width, screen_height))
    pygame.display.set_caption("Happy new year!")  # 标题
    background = pygame.image.load(os.path.join("beijing.jpg"))  # 背景
    # background=pygame.transform.scale(background,(screen_width,screen_height))
    # background_width,background_height=background.get_size()
    # background_x=(screen_width-background_width)//2
    # background_y=(screen_height-background_height)//2
    # screen.blit(background,(background_x,background_y))
    # pygame.display.flip()
    # while True:
    #     for event in pygame.event.get():
    #         if event.type == pygame.QUIT:
    #             pygame.quit()
    #             exit()
    mpl.rcParams['font.sans-serif'] = ['SimHei']
    myfont = pygame.font.Font("ziti.otf", 80)
    myfont1 = pygame.font.Font("ziti.otf", 20)
    # myfont = pygame.font.Font(None)
    # myfont1 = pygame.font.Font(None)

    testsurface = myfont.render("新年快乐!", False, (251, 59, 85))
    testsurface1 = myfont1.render("By:寂空", False, (251, 59, 85))
    # pygame.image.load("")
    win = pygame.display.set_mode((DISPLAY_WIDTH, DISPLAY_HEIGHT))
    # win.blit(background)
    clock = pygame.time.Clock()

    fireworks = [Firework() for i in range(2)]  # create the first fireworks
    running = True

    while running:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN:  # Change game speed with number keys
                if event.key == pygame.K_1:  # 按下 1
                    fireworks.append(Firework())
                if event.key == pygame.K_2:  # 按下 2 加入10个烟花
                    for i in range(10):
                        fireworks.append(Firework())
        win.fill((20, 20, 30))  # draw background
        win.blit(background, (0, 0))
        win.blit(testsurface, (200, 30))
        win.blit(testsurface1, (600, 100))

        if randint(0, 20) == 1:  # create new firework
            fireworks.append(Firework())

        update(win, fireworks)
        # stats for fun
        # total_particles = 0
        # for f in fireworks:
        #    total_particles += len(f.particles)

        # print(f"Fireworks: {len(fireworks)}\nParticles: {total_particles}\n\n")

    pygame.quit()
    quit()


main()
