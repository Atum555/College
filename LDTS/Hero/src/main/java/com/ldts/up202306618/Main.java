package com.ldts.up202306618;

import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try {
            new Game().run();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
