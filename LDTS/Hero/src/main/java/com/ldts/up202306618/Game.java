package com.ldts.up202306618;

import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.swing.SwingTerminalFontConfiguration;

import java.io.IOException;

public class Game {
    private static final int SCREEN_WIDTH = 60;
    private static final int SCREEN_HEIGHT = 20;

    private final Screen screen;
    private final Arena arena;
    private boolean running;

    public Game() {
        try {
            // Init Screen
            this.screen = new DefaultTerminalFactory()
                    .setInitialTerminalSize(new TerminalSize(SCREEN_WIDTH, SCREEN_HEIGHT))
                    .setTerminalEmulatorFontConfiguration(
                            SwingTerminalFontConfiguration.getDefaultOfSize(26)
                    )
                    .createScreen();
            this.screen.setCursorPosition(null);
            this.screen.startScreen();
            this.screen.doResizeIfNecessary();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        this.arena = new Arena(SCREEN_WIDTH, SCREEN_HEIGHT);
        this.running = true;
    }

    public void run() throws IOException {
        while (this.running) {
            // Redraw Game
            this.draw();

            // Process Input
            KeyStroke key = screen.readInput();
            this.processKey(key);

            // Update Game
            if (!this.arena.update()) this.running = false;
        }

        // Game Stopped running
        this.screen.close();
    }

    private void draw() throws IOException {
        // Clear Screen
        this.screen.clear();

        // Draw Arena
        TextGraphics graphics = screen.newTextGraphics();
        this.arena.draw(graphics);

        // Refresh Screen
        this.screen.refresh();
    }

    private void processKey(KeyStroke key) {
        switch (key.getKeyType()) {
            case ArrowUp, ArrowDown, ArrowLeft, ArrowRight -> this.arena.processKey(key);
            case EOF -> this.running = false;

            case Character -> {
                switch (key.getCharacter()) {
                    case 'q', 'Q' -> this.running = false;
                    case null, default -> {
                    }
                }
            }
            case null, default -> {
            }
        }
    }
}
