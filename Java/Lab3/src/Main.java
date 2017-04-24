

import java.io.IOException;
import java.util.*;
import java.util.regex.*;
import java.nio.file.*;

enum ConsoleColor
{
    GREY("\u001B[30m"),
    RED("\u001B[31m"),
    GREEN("\u001B[32m"),
    BLUE("\u001B[34m"),
    PURPLE("\u001B[35m"),
    CYAN("\u001B[36m"),
    WHITE("\u001B[37m");

    private String code;

    ConsoleColor(String code)
    {
        this.code = code;
    }

    public String getCode()
    {
        return code;
    }
}

class Lexeme {
    private Type type;
    private int start;
    private int end;

    public Lexeme(Type type, int start, int end) {
        this.type = type;
        this.start = start;
        this.end = end;
    }

    public Type getType() {
        return type;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }

    enum Type {
        SINGLE_COMMENT("/" + "/(.|\\n)*?[^\\\\]\\n"),
        MULTILINE_COMMENT("/\\*(.|\\n)*?\\*/"),
        COMMENT(ConsoleColor.GREEN, SINGLE_COMMENT.pattern, MULTILINE_COMMENT.pattern),

        STRING("\"[^\"]*\""),
        CHAR("\'[^\']*\'"),
        LITERALS(ConsoleColor.CYAN, STRING.pattern, CHAR.pattern),

        FLOAT_SIMPLE("((\\d+\\.\\d*|\\.\\d+|\\d+)[fF]?)"),
        FLOAT_SCIENTIFIC("((\\d+\\.\\d*|\\.\\d+|\\d+)[eE][+-]?\\d+[fF]?)"),
        FLOAT(FLOAT_SIMPLE.pattern, FLOAT_SCIENTIFIC.pattern),

        HEX("(?<!\\w)(0x[0-9a-fA-F]+[LlUu]?)(?!\\w)"),
        OCT("(?<!\\w)(0[0-7]+[LlUu]?)(?!\\w)"),
        DEC("(?<!\\w)(\\d+[LlUu]?)(?!\\w)"),
        INTEGER(HEX.pattern, OCT.pattern, DEC.pattern),
        NUMBER(ConsoleColor.CYAN, FLOAT.pattern, INTEGER.pattern),

        KEYWORD(
                ConsoleColor.BLUE,
                "(?<!\\w)(abstract|assert|break|case|catch|class|const|continue|default" +
                        "|do|else|enum|extends|final|finally|for|goto|if|implements|" +
                        "import|instanceof|interface|native|new|package|private|" +
                        "protected|public|return|short|static|strictfp|super|switch|" +
                        "synchronized|this|throws|throw|transient|try|volatile|while)(?!\\w)"),

        OPERATOR(ConsoleColor.PURPLE, "[~!%^&*+=|?:<>\\/-]"),
        TYPE(
                ConsoleColor.BLUE,
                "(?<!\\w)(boolean|byte|char|double|float|int|long|short|void)(\\[\\])*(?!\\w)"),
        PUNCTUATION(ConsoleColor.RED, "[()\\[\\],.;]");
        private ConsoleColor color;
        private String pattern;

        Type(ConsoleColor color, String... patterns) {
            this.color = color;
            this.pattern = "(" + patterns[0] + ")";
            StringBuilder b = new StringBuilder("(" + patterns[0] + ")");
            for (int i = 1; i < patterns.length; ++i)
                b.append("|(" + patterns[0] + ")");
            this.pattern = b.toString();
        }

        Type(String... patterns) {
            this(ConsoleColor.GREY, patterns);
        }

        public ConsoleColor getColor() {
            return color;
        }

        public Pattern compilePattern() {
            return Pattern.compile(pattern);
        }
    }
}

class Highlighter
{
    public static String highlight(String text)
    {
        List<Lexeme> lexemes = new ArrayList<>();

        lexemes.addAll(findLexemes(text, Lexeme.Type.COMMENT));
        lexemes.addAll(findLexemes(text, Lexeme.Type.LITERALS));
        lexemes.addAll(findLexemes(text, Lexeme.Type.KEYWORD));
        lexemes.addAll(findLexemes(text, Lexeme.Type.OPERATOR));
        lexemes.addAll(findLexemes(text, Lexeme.Type.NUMBER));
        lexemes.addAll(findLexemes(text, Lexeme.Type.TYPE));
        lexemes.addAll(findLexemes(text, Lexeme.Type.PUNCTUATION));

        return highlightLexemes(text, lexemes);
    }

    private static List<Lexeme> findLexemes(String text, Lexeme.Type type)
    {
        Matcher m = type.compilePattern().matcher(text);
        List<Lexeme> lexemes = new ArrayList<>();
        while (m.find()) lexemes.add(new Lexeme(type, m.start(), m.end()));
        return lexemes;
    }

    private static String highlightLexemes(String text, List<Lexeme> lexemes)
    {
        final String ANSI_RESET = "\u001B[0m";
        StringBuilder builder = new StringBuilder(text);

        lexemes.sort((x, y) -> x.getEnd() > y.getEnd() || x.getEnd() == y.getEnd() && x.getStart() < y.getStart() ? -1 : 1);
        int l = text.length();
        for (Lexeme lexeme : lexemes) {
            if (lexeme.getEnd() <= l) {
                builder.insert(lexeme.getEnd(), ANSI_RESET);
                builder.insert(lexeme.getStart(), lexeme.getType().getColor().getCode());
                l = lexeme.getStart();
            }
        }
        return builder.toString();
    }
}

public class Main {

    public static void main(String[] args) throws IOException
    {
        String text = new String(Files.readAllBytes(Paths.get("C:/m.txt")));
        System.out.println(Highlighter.highlight(text));
    }
}