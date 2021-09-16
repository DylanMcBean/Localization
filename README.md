# Localization

## What is this?
- this is a tool to help with localization in games so you can have multiple different languages and have a system that then lets you select different languages from a main point without having to do in and change your entire code base.


**Code View**
```cpp
  LocalizationHandler local;
  local.SetLanguage(LocalizationHandler::languages::English);

  std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HAPPY") << "\n";
  std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.SAD") << "\n";
  std::cout << local.Localize("STRINGS.CHARACTER.GREETINGS.HELLO", new std::string[]{ "John" }) << "\n";
  std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.HURT") << "\n";
  std::cout << local.Localize("STRINGS.CHARACTER.COMBAT.ATTACK") << "\n\n";
```

The only line that would need to be changed is `local.SetLanguage(LocalizationHandler::languages::English);`, so you would change the `languages::English` to something like `languages::German` if you had a German translation file and it would then change all the text in the game to be read from your German file instead of the English file as easy as that.


## File Previews

**English**
```
STRINGS =
{
  CHARACTER = 
  {
    GREETINGS = 
    {
      HELLO = "Hello my name is {}, Nice to meet you.",
      HAPPY = "I'm very (happy,jolly,cheerful,merry,content,gleeful) just now. isn't it just a (lovely,pretty,appealing) (day today,night tonight)",
      SAD = "I'm not feeling (very good,great,well), its just been a( rough, tough, wrong, off, hard, unlucky,n awful) (day today,night tonight)"
    },
    COMBAT = 
    {
      DEFEND = "Stay back, this one's (powerful,strong)",
      ATTACK = "Take that you (monster,bully,bad guy)",
      HURT = "(ouch,owww,that hurt,tis but a scratch)"
    },
    SHOP =
    {
      BUY = "I would like to buy {} of those {} you (got,have) there.",
      SELL = "Hello {}, are you intrested in (some,any) of my {}.",
      OUT_OF_STOCK = "Sorry I dont have any items at the moment, come back (later,some other time,tomorrow) and I should (have more items,be restocked)."
    }
  }
}
```

**German**
```
STRINGS =
{
  CHARACTER = 
  {
    GREETINGS = 
    {
      HELLO = "Hallo, mein Name ist {}, Schön, Sie kennenzulernen.",
      HAPPY = "Ich bin gerade sehr (fröhlich, fröhlich, fröhlich, fröhlich, zufrieden, fröhlich). ist es nicht einfach ein (schöner, hübscher, ansprechender) (Tag heute, Nacht heute Abend)",
      SAD = "Ich fühle mich nicht (sehr gut, großartig, gut), es war nur ein (rauher, zäher, falscher, schlechter, harter, unglücklicher, schrecklicher) Tag heute, Nacht heute Nacht."
    },
    COMBAT = 
    {
      DEFEND = "Zurückbleiben, der hier ist (mächtig, stark)",
      ATTACK = "Nehmen Sie das Sie (Monster, Tyrann, Bösewicht)",
      HURT = "(autsch,autsch,das tat weh,es ist nur ein Kratzer)"
    },
    SHOP =
    {
      BUY = "Ich möchte {} dieser {} kaufen, die Sie dort gekauft (haben) haben.",
      SELL = "Hallo {}, interessieren Sie sich für (einige, irgendwelche) meiner {}?",
      OUT_OF_STOCK = "Es tut mir leid, dass ich im Moment keine Artikel habe, kommen Sie wieder (später, ein anderes Mal, morgen) und ich sollte (mehr Artikel haben, wieder auf Lager sein)."
    }
  }
}
```

**French**
```
STRINGS =
{
  CHARACTER = 
  {
    GREETINGS = 
    {
      HELLO = "Bonjour, je m'appelle {}, Ravi de vous rencontrer.",
      HAPPY = "Je suis très (heureux,jovial,joyeux,content,gai) en ce moment. N'est-ce pas juste un (charmant,joli,attirant) (jour aujourd'hui,nuit ce soir)",
      SAD = "Je ne me sens pas (très bien,super,bien), c'était juste un (rude,dur,mal,off,dur,malchanceux,n horrible) (jour aujourd'hui,nuit ce soir)"
    },
    COMBAT = 
    {
      DEFEND = "Restez en arrière, celui-ci est (puissant,fort)",
      ATTACK = "Prends ça toi (monstre,brute,méchant)",
      HURT = "(ouch, owww,ça fait mal,ce n'est qu'une égratignure)"
    },
		SHOP =
    {
      BUY = "Je voudrais acheter {} de ces {} que vous (avez, avez) là.",
      SELL = "Bonjour {}, êtes-vous intéressé par (certains, n'importe lesquels) de mes {}.",
      OUT_OF_STOCK = "Désolé, je n'ai pas d'articles pour le moment, revenez (plus tard, une autre fois, demain) et je devrais (avoir plus d'articles, être réapprovisionné)."
    }
  }
}
```

the `{}` symbolize parts where a varible will be subbed into it's place, and parts surrounded by `()` and seperated by `,` are parts that will be randomly chosen.
