package com.ldts.up202306618;

import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.ldts.up202306618.elements.Coin;
import com.ldts.up202306618.elements.Hero;
import com.ldts.up202306618.elements.Monster;
import com.ldts.up202306618.elements.Wall;
import com.ldts.up202306618.utils.Position;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Arena {
    private final int width;
    private final int height;

    private final Hero hero;
    private final List<Wall> walls;
    private final List<Coin> coins;
    private final List<Monster> monsters;

    public Arena(int width, int height) {
        this.width = width;
        this.height = height;

        this.hero = new Hero(new Position(10, 10));
        this.walls = new ArrayList<>();
        this.coins = new ArrayList<>();
        this.monsters = new ArrayList<>();
        this.createWalls();
        this.createCoins();
        this.createMonsters();
    }

    public void draw(TextGraphics graphics) {
        // Draw BackGround
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.fillRectangle(
                new TerminalPosition(0, 0),
                new TerminalSize(width, height),
                ' '
        );

        // Draw Walls
        this.walls.forEach(wall -> wall.draw(graphics));

        // Draw Coins
        this.coins.forEach(coin -> coin.draw(graphics));

        // Draw Monsters
        this.monsters.forEach(monster -> monster.draw(graphics));

        // Draw Hero
        this.hero.draw(graphics);
    }

    public void processKey(KeyStroke key) {
        switch (key.getKeyType()) {
            case ArrowUp -> this.moveHero(this.hero.moveUp());
            case ArrowDown -> this.moveHero(this.hero.moveDown());
            case ArrowLeft -> this.moveHero(this.hero.moveLeft());
            case ArrowRight -> this.moveHero(this.hero.moveRight());
            case null, default -> {
            }
        }
    }

    public boolean update() {
        // Catch Coins
        for (Coin coin : this.coins)
            if (coin.getPosition().equals(this.hero.getPosition())) {
                this.coins.remove(coin);
                break;
            }

        // Update Monsters
        Random random = new Random();
        for (Monster monster : this.monsters)
            this.moveMonster(
                    monster,
                    new Position(
                            monster.getPosition().getX() + random.nextInt(3) - 1,
                            monster.getPosition().getY() + random.nextInt(3) - 1
                    )
            );

        // Check if Hero died
        for (Monster monster : this.monsters) if (monster.getPosition().equals(this.hero.getPosition())) return false;
        return true;
    }

    private void moveHero(Position newPosition) {
        if (canMove(newPosition)) this.hero.setPosition(newPosition);
    }

    private void moveMonster(Monster monster, Position newPosition) {
        if (canMove(newPosition)) monster.setPosition(newPosition);
    }

    private boolean canMove(Position newPosition) {
        // Check Arena Limits
        if (newPosition.getX() < 0) return false;
        if (newPosition.getY() < 0) return false;
        if (newPosition.getX() >= this.width) return false;
        if (newPosition.getY() >= this.height) return false;

        // Check Collisions with walls
        for (Wall wall : this.walls) if (wall.getPosition().equals(newPosition)) return false;

        return true;
    }

    private void createWalls() {
        for (int x = 0; x < this.width; x++) {
            this.walls.add(new Wall(new Position(x, 0)));
            this.walls.add(new Wall(new Position(x, this.height - 1)));
        }

        for (int y = 1; y < this.height - 1; y++) {
            this.walls.add(new Wall(new Position(0, y)));
            this.walls.add(new Wall(new Position(this.width - 1, y)));
        }
    }

    private void createCoins() {
        Random random = new Random();
        while (this.coins.size() < 30) {
            Position randomPosition = new Position(
                    random.nextInt(width - 2) + 1,
                    random.nextInt(height - 2) + 1
            );

            if (isFreePosition(randomPosition)) this.coins.add(new Coin(randomPosition));
        }
    }

    private void createMonsters() {
        Random random = new Random();
        while (this.monsters.size() < 20) {
            Position randomPosition = new Position(
                    random.nextInt(width - 2) + 1,
                    random.nextInt(height - 2) + 1
            );

            if (isFreePosition(randomPosition)) this.monsters.add(new Monster(randomPosition));
        }
    }

    private boolean isFreePosition(Position position) {
        if (position.equals(this.hero.getPosition())) return false;
        for (Wall wall : this.walls) if (position.equals(wall.getPosition())) return false;
        for (Coin coin : this.coins) if (position.equals(coin.getPosition())) return false;
        return true;
    }
}
