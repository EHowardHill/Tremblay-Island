int exec_dialogue(int x) {

    constexpr bool fals = false;
    constexpr int n = -1;

    switch (x) {
        case 0: {
            line lc[32] = {
                {fals, true, 0, "BG: 1"},
                {fals, true, 0, "S01:01"},
                {fals, true, 0, ""},
                {fals, true, 0, "4:15 AM                          January 1st, 2000                Providence of Nord Louisiane,    La République Laurentides"},
                {fals, true, 0, "S01:02"},
                {fals, true, 0, "                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind."},        
                {fals, true, 0, "S01:03"},
                {fals, true, 0, "                                 Look at that gumbo.              It has to be cold by now.        I can't believe they wanted me   to bring the food."},
                {fals, true, 0, "S01:04"},
                {fals, true, 0, "                                 Y'know....                       If I don't see that castle in    fifteen minutes, I might just    head back."},
                {fals, true, 0, "                                 At least the drive was nice,     I guess."},
                {fals, true, 0, "S01:05"},
                {fals, true, 0, "                                 Okay, I give up. There's no way  that I'm gonna-"},
                {fals, true, 0, "S01:06"},
                {fals, true, 0, "                                 .....Oh."},
                {fals, true, 0, "                                 I.. can't decide if I'm          relieved or disappointed."},
                {fals, true, 0, "BG: fadeout"},
                {fals, true, 0, "S01:07"},
                {fals, true, 0, "                                 *knock*                          *knock*                          *knock*"},
                {fals, true, 0, "S01:08"},
                {fals, true, 0, "                                 I wonder if they can even        hear me in there... This place   looks huge."},
                {fals, true, 0, "                                                                  '.....coming!'"},
                {fals, true, 0, "S01:09"},
                {fals, true, 0, "BG: 0"},
                {fals, true, 0, "                                                                  Hey, Maple!!                     C'mon in, allez!"},
                {fals, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 1: {
            line lc[32] = {
                {true, true, 0, "BG: Ocean"},
                {true, fals, 1, "MAPLE                            Alright, so where do I plug this crock-pot in at? Are there any   plugs?"},
                {fals, fals, 1, "MAPLE                            I take it that I'm late enough   y'all probably already ate       something else."},
                {fals, true, 9, "ENOKI                            Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken."},
                {fals, true, 8, "ENOKI                            We missed you earlier :("},
                {fals, fals, 5, "MAPLE                            Well I'm finally here, now. So,  where is- Oh! Salut, Aaron."},
                {true, true, 10, "AARON                            Bonsoir! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!"},
                {fals, fals, 3, "MAPLE                            Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?"},
                {true, true, 12, "DEL                              Maple! You're here! Happy 2000!"},
                {fals, fals, 5, "MAPLE                            Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!"},
                {fals, true, 13, "DEL                              Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up."},
                {fals, true, 12, "DEL                              We're all boring adults, though, so no promises about how late we would have stayed up for you."},
                {true, true, 7, "ENOKI                            So Maple, what have you been up  to lately? Have we even talked   since the wedding?? I missed my  best friend :("},
                {fals, fals, 2, "MAPLE                            Surely your husband's been       keeping you busy, I suppose."},
                {true, true, 10, "AARON                            Well, we're obviously living in acastle now, so that's been an    adventure."},
                {true, true, 7, "ENOKI                            I am a princess."},
                {fals, fals, 2, "MAPLE                            It takes a little more than just a castle to be a princess."},
                {fals, true, 8, "ENOKI                            I'm a duchess?"},
                {fals, fals, 4, "MAPLE                            I- uhm...                        Hmm...                           You know what?                   It's too late for this."},
                {fals, fals, 2, "MAPLE                            Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know."},
                {true, true, 10, "AARON                            Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?"},
                {fals, true, 11, "AARON                            Are there no degrees for people  who can shoot fire out of their  hands?"},
                {fals, fals, 4, "MAPLE                            ...None I want, at least."},
                {fals, true, 10, "AARON                            Well, a teacher with fire magic  sounds pretty cool to me."},
                {true, true, 8, "ENOKI                            *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?"},
                {fals, true, 7, "ENOKI                            Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?"},
                {fals, fals, 2, "MAPLE                            I mean... Sure, I guess."},
                {fals, true, n, "ENOKI                            Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?"},
                {fals, true, 0, "AARON                            Sure thing, Noke-noke.                                            *kiss*"},
                {fals, fals, 3, "MAPLE                            I am never going to get used to  that."},
                {true, true, 9, "ENOKI                            Alright, grab your bag and I'll  show you where we're staying.    Allons-y!"},
                    {true, true, 0, "COM: Endscene"}
                };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 2: {
            line lc[32] = {
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "S01:11"},
                {true, true, 0, "MAPLE                            Wow.. It's sort of chilly in     here, isn't it?"},
                {true, true, 0, "ENOKI                            Well silly, why'd ya wear a tank top and shorts in the middle of  December? Can't ya just light a  fire?"},
                {true, true, 0, "BG: 2"},
                {true, true, 0, "S01:10"},
                {true, true, 0, "MAPLE                            So, how long are you two going tostay here? You can't just stay   thirty miles from civilization   without electricity forever."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            We're happy, so we think a long  time."},
                {true, true, 0, "MAPLE                            I mean, what does Aaron think of all this? The Aaron I remember   growing up would be a little more...responsible."},
                {true, true, 0, "ENOKI                            I don't wanna sound rude but...  Aren't you guys used to growing  up in places like, er, in a car?"},
                {true, true, 0, "MAPLE                            Enoki, we all know you're rich,  no need to flaunt it."},
                {true, true, 0, "ENOKI                            But didn't you literally grow up in a car? I mean, compared to    that, a castle is pretty nice,   right?"},
                {true, true, 0, "MAPLE                            It just seems.. rash. I don't    mean to take the fun out of it,  but I can't help but think this  was a really, really bad idea."},
                {true, true, 0, "ENOKI                            Coming from the girl who got     embarrased of her grades freshmanyear and decided to just up and  run away from college."},
                {true, true, 0, "S01:10"},
                {true, true, 0, "MAPLE                            Oh come on, that was your idea   first."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            Hey, I'll take it!! '97... Yeah, that was one of the best years   of my life, easy."},
                {true, true, 0, "ENOKI                            So, after college, you got any   plans for where you wanna live?"},
                {true, true, 0, "MAPLE                            I'll figure something out."},
                {true, true, 0, "ENOKI                            Aaron and I were chatting and,   y'know, there's a school not too far off you could teach at,      maybe you could.. y'know.."},
                {true, true, 0, "MAPLE                            Absolutely NOT. I'll make sure   to get myself a real adult       apartment."},
                {true, true, 0, "MAPLE                            When you get tired of this place,maybe you can move in with me."},
                {true, true, 0, "S01:12"},
                {true, true, 0, "ENOKI                            The kinda things you choose to befunny about Maple, it'll never   cease to amaze me."},
                {true, true, 0, "S01:11"},
                {true, true, 0, "ENOKI                            Hey- I'm feeling down and that's stupid! You wanna go on another  Maple and Enoki adventure like   old times??"},
                {true, true, 0, "ENOKI                            Let's go explore the castle!!"},
                {true, true, 0, "MAPLE                            Hold up, you bought this castle  and hadn't explored it all first?"},
                {true, true, 0, "ENOKI                            Well duh, I'm taking my sweet    time with it -- it's a castle!    Allons-y, let's explore!"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 13: {
            line lc[32] = {
                {true, true, 0, "S01:13"},
                {true, fals, 4, "..."},
                {true, true, 10, "AARON                            Bonjour! Did you sleep well?"},
                {fals, fals, 4, "MAPLE                            Yeah, it was ok I guess."},
                {true, true, 9, "ENOKI                            Bonjour! So.. We found something cool while you were sleeping, butyou've gotta promise you won't bemad."},
                {fals, fals, 4, "MAPLE                            You know I can't promise that."},
                {fals, true, 7, "ENOKI                            Remember that book you wanted me to get? Well, it's a world atlas!And we spotted something really  fun!"},
                {fals, true, 9, "ENOKI                            So, we found this island up in   Lake Supérieur called Tremblay  Island!"},
                {fals, fals, 0, "MAPLE                            Aw, that's fun. I was afraid thatthere'd be some kind of.. catch."},
                {fals, true, 0, "ENOKI                            Well, we, uh- figured it'd be funif, well, the idea came from Del,so..."},
                {true, true, 12, "DEL                              Last time we talked, my cousin   Rufus was obsessed with starting his own tiny country."},
                {true, true, 11, "AARON                            There's work not too far out, so if we need to pick up supplies,  it shouldn't be very difficult."},
                {true, true, 7, "ENOKI                            With the money we could make     selling off the castle, and with your magic, we were thinking-"},
                {fals, fals, 3, "MAPLE                            WHOA WHOA WHOA,                  JUST HOLD UP FOR A MINUTE."},
                {fals, fals, 3, "MAPLE                            Are you seriously telling me thatyou're going to SELL this castle and move to this random island,"},
                {fals, fals, 3, "MAPLE                            All because it shares the same   last name as us?"},
                {fals, true, 9, "ENOKI                            As a bonus, we're thinking we're gonna secede from the Laurentidesand be our own country, too."},
                {fals, fals, 0, "MAPLE                            ...I..."},
                {fals, fals, 0, "MAPLE                            ..."},
                {fals, fals, 4, "MAPLE                            ...I'm going to need some time toprocess this."},
                {true, true, 10, "AARON                            It sounds insane, but we've gone over the details, and it seems   like this could actually happen."},
                {true, true, 9, "ENOKI                            I know we had that talk last     night, but.."},
                {fals, fals, 3, "MAPLE                            And then what's next?            What happens after you get bored of being your own little island?"},
                {fals, fals, 0, "MAPLE                            Do you want to be the Pope? The  Queen of France? Are you going towant your own planet?"},
                {fals, fals, 0, "MAPLE                            And for what it's worth you're   lucky enough that you'll probablyget it. But you know what?"},
                {fals, fals, 0, "MAPLE                            I'm going to settle in reality   with my *real* job and stay out  of starving to death on some     rock,"},
                {fals, fals, 0, "MAPLE                            Or worse, getting locked up in   federal prison for breaking some sort of weird law."},
                {fals, fals, 4, "MAPLE                            Look.... It's been fun, but I    need to go home. I'm done with   this."},
                {fals, fals, 0, "MAPLE                            Aaron, Enoki, Delphine, it's beenfun, but.... I need some time."},
                {true, true, 10, "AARON                            Are you sure? We can change the  subject, we were just talking.   We've got breakfast made if you  want some."},
                {fals, fals, 0, "MAPLE                            ..Alright, I'll stay a little    longer, but I do need to be      heading out soon."},
                {true, true, 0, "COM: Endscene"}
                };
            dialogue_page(lc);
            return 0;
			break;
        };

        case 14: {
            line lc[32] = {
                {true, true, 0, "S02:02"},
                {true, true, 0, "BG: champ"},
                {true, true, 0, "                                                                                                   Hmm, hmm hmm hmm...."},
                {true, true, 0, "For goodness' sake, when is that pizza going to show up? Wasn't itsupposed to be here in under     twenty minutes?"},
                {true, true, 0, "                                 Have I checked my mail today? I  probably should go ahead and     check."},
                {true, true, 0, "S02:03"},
                {true, true, 0, "Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while."},
                {true, true, 0, "                                                                  Can't wait to read about how muchthey want to move in with me now."},
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "S02:04"},
                {true, true, 0, "                                             Hey, Maple!"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "Hold on, got this backwards."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "BG: 0"},
                {true, true, 0, "                                             'Hey, Maple!'"},
                {true, true, 0, "      'We thought we'd send            you a quick letter to            give you an update.'"},
                {true, true, 0, "      'We sold the castle and          got to make enough to            buy a nice trailer home.'"},
                {true, true, 0, "      'However, that's not all-        we got it set up on our          new island!!'"},
                {true, true, 0, "S02:05"},
                {true, true, 0, "I'm...                           That's it,                       I'm gonna kill 'em."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "      'So, we've decided that          we're going to name it-..'"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
			break;
        };      

        case 15: {
            line lc[32] = {
                {true, true, 0, "S02:06"},
                {true, true, 0, "MAPLE                            Thunder my DOG,                  I have had ENOUGH,               they are ALL gonna get it!"},
                {true, true, 0, "MAPLE                            That's it! I'm at my limit.      They're going to DIE ALONE and   it's gonna be ALL their fault."},
                {true, true, 0, "MAPLE                            When they're tired of living thisisland fantasy, they're gonna    come here, and you know what I'llsay?"},
                {true, true, 0, "PIZZA GUY                        What will you say?"},
                {true, true, 0, "S02:07"},
                {true, true, 0, "MAPLE                            I'll say NO!"},
                {true, true, 0, "PIZZA GUY                        I dunno, living on an island by  yourself sounds kinda nice."},
                {true, true, 0, "MAPLE                            It's the nicest thing on the     planet, but they're gonna ruin itcos they're the most incompetant people on the planet!"},
                {true, true, 0, "PIZZA GUY                        If I were you, I'd go up and     teach 'em how to run the island."},
                {true, true, 0, "MAPLE                            I guess I'm gonna have to huh?   They're gonna die up there or    freeze to death!"},
                {true, true, 0, "MAPLE                            But I can't. I've gotta be the   better person and stay in adult  world."},
                {true, true, 0, "S02:06"},
                {true, true, 0, "PIZZA GUY                        Right, it's more important to    keep buying pizza and crying     yourself to sleep on your couch  like ya' do every night?"},
                {true, true, 0, "S02:08"},
                {true, true, 0, "MAPLE                            Is it really that obvious?"},
                {true, true, 0, "PIZZA GUY                        Yeah, we all take turns at the   place to see who'll get to       deliver to the 'sad pizza girl'."},
                {true, true, 0, "MAPLE                            Spectacular."},
                {true, true, 0, "S02:04"},
                {true, true, 0, "MAPLE                            Well, I suppose....              I mean, I don't exactly have the money to pay rent this month cos of all the pizza..."},
                {true, true, 0, "PIZZA GUY                        So... we gonna tip for today's   counseling session?"},
                {true, true, 0, "BG: fadeout"},
                {true, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        };

        case 16: {
            // Spring
            line lc[32] = {
                {fals, true, 0, "S03:01"},
                {fals, true, 0, "BG: 1"},
                {fals, true, 0, "6:40 PM                          March 20th, 2000                 The middle of Lake Supérieur,   La République Laurentides(?)"},
                {fals, true, 0, "                                 So.. That's the island.          It's cute."},
                {fals, true, 0, "                                 I'm not sure if it's sell-every- thing-I-own cute, but..."},
                {fals, true, 0, "                                 J'suppose the thought of living  on an island and having no debt  is pretty cool."},        
                {fals, true, 0, "S03:02"},
                {fals, true, 0, "MAPLE                            How much was the ferry again?    10 dollars?"},
                {fals, true, 0, "OLD SAILOR                       Aye lass, but aye've got one     warnin' fer ye befer ye dock."},
                {fals, true, 0, "MAPLE                            Oh dear, what?"},
                {fals, true, 0, "OLD SAILOR                       Keep yer wits about 'ye, ye neverknow who might go to stab ye."},
                {fals, true, 0, "MAPLE                            Will you take a 20?"},
                {fals, true, 0, "OLD SAILOR                       Aye, I can cut a 20."},
                {fals, true, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 18: {
            line lc[32] = {
                {fals, fals, 0,  "BG: Trailer Home"},
                {true, true, 22, "ENOKI                            Maple!! You came!"},
                {true, fals, 17, "MAPLE                            Yeah, this was my best option."},
                {true, true, 24, "AARON                            How was the trip? Did it take youlong?"},
                {fals, fals, 16, "MAPLE                            I took the train. It was like..  three days? It was fine. I read alot. My legs hurt."},
                {fals, true, 25, "AARON                            If you'd had let us know you werecoming sooner, you know we would have arranged for a plane trip!"},
                {fals, fals, 18, "MAPLE                            Doesn't matter. I'm already here.So, you go from castle to mobile home? Classy."},
                {true, true, 20, "ENOKI                            Dude, we moved outta the castle  in a 'normal home' and now you   want us to go back?"},
                {fals, fals, 16, "MAPLE                            No, I mean.. I guess I don't     know what I mean."},
                {true, true, 26, "AARON                            Well, we've only got a couch, butit's very comfortable. Feel free to make yourself at home."},
                {fals, true, 24, "AARON                            We've been working hard. I've    been chopping wood for the winterand Enoki's been-"},
                {true, true, 22, "ENOKI                            So, I, uh, I thought bringing    some bunnies here would make the island a little more alive,      y'know?"},
                {fals, true, 20, "ENOKI                            Turns out they started           multiplying so I spenda lotta    time tryna' keep em out of the   garden."},
                {true, true, 26, "AARON                            How do you feel about going into the caves a little north of here?"},
                {fals, true, 24, "AARON                            We've heard there's some gems in there that could be really       useful in earning us some money."},
                {fals, fals, 14, "MAPLE                            I guess that isn't too difficult."},
                {fals, fals, 15, "MAPLE                            Hey... thanks for the room."},
                {fals, true, 25, "AARON                            No problem."},
                {fals, true, 22, "ENOKI                            Oh, and if you haven't met Scout yet, he's pretty cool! He's down in the bunker thing outside."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 17: {
            line lc[32] = {
                {fals, fals, 0,  "BG: Trailer Home"},
                {true, true, 22, "ENOKI                            Well.. First day is done! I thinktoday was a lot of fun."},
                {true, fals, 17, "MAPLE                            You know what? I think I agree.  This is the most interesting day I've had in a while."},
                {true, true, 24, "AARON                            Ready to change your mind about  this having been a bad idea?"},
                {fals, fals, 16, "MAPLE                            I've only been here a day, I'll  give it some time before I make  my final judgement."},
                {fals, true, 25, "AARON                            Well, we're happy to have you.   I'm sorry, we only have a couch, but I'm working on a new home."},
                {fals, fals, 18, "MAPLE                            Oh, I slept on my couch back at  my old apartment all the time.   No need to worry."},
                {true, true, 20, "ENOKI                            Aw, you slept on a couch?"},
                {fals, fals, 16, "MAPLE                            It was a really nice couch."},
                {true, true, 26, "AARON                            Anyway, we're gonna get some     sleep. I've been chopping wood   all day and I'm tired."},
                {fals, true, 24, "AARON                            See you tomorrow?"},
                {true, true, 22, "ENOKI                            I'm sure I'll find more stuff to do!"},
                {fals, fals, 15, "MAPLE                            Thanks again. I'll do my best to not be a butt about all this.    Goodnight, y'all."},
                {fals, true, 22, "ENOKI                            Bonne nuit!"},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 19: {
            line lc[32] = {
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "S04:01"},
                {fals, fals, 0,  "                                 Ugh.. My head.                   Why can't I sleep?"},
                {fals, fals, 0,  "                                 Aren't you supposed to be able tosleep easier after a long day of travel and manual labor?"},
                {fals, fals, 0,  "                                 And where's that light coming    from outside? Probably Scout or  something."},
                {fals, fals, 0,  "                                 Maybe I should go on a walk and  check it out."},
                {fals, fals, 0,  "S04:02"},
                {fals, fals, 0,  "                                 What the-                        is that a Mons d'Plonj? Is he    writing something?"},
                {fals, fals, 0,  "                                 I guess I should go check it out.Before something bad happens."},
                {fals, fals, 0,  "S04:03"},
                {fals, fals, 0,  "                                 Hmmm, hmmm... hmmm...."},
                {fals, fals, 0,  "S04:04"},
                {fals, fals, 0,  "MAPLE                            HEY! IDENTIFY YOURSELF, OR I'LL  BURN YOUR FACE OFF!"},
                {fals, fals, 0,  "S04:05"},
                {fals, fals, 0,  "                                 AHHHH?!"},
                {fals, fals, 0,  "                                 AH, UH.. UH, RUFUS!              RUFUS THIBODEAUX!"},
                {fals, fals, 0,  "                                 DON'T BURN MY FACE OFF, I NEED   THAT!"},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }

        case 20: {
            line lc[32] = {
                {fals, fals, 0,  "BG: frog"},
                {fals, fals, 0,  "S04:06"},
                {fals, fals, 0,  "MAPLE                            Oh, so you're /that/ Rufus? Del'scousin, right? I'm Maple."},
                {fals, fals, 0,  "RUFUS                            Oh, you're the fire elf, right?  Wish I knew that earlier when I  was trying to get this fire      started."},
                {fals, fals, 0,  "MAPLE                            What are you doing here?"},
                {fals, fals, 0,  "RUFUS                            Just checking things out. I've   got my eye on the Bill & Jim     Islands next door."},
                {fals, fals, 0,  "RUFUS                            I really like the idea of just   having my own place and not      having to talk to anyone."},
                {fals, fals, 0,  "RUFUS                            I'm just worried this whole      'private island' thing is...     kind of foolhardy."},
                {fals, fals, 0,  "RUFUS                            Everyone this close to Quebec    speaks with that annoying accent,too."},
                {fals, fals, 0,  "MAPLE                            That's what I was afraid of, too.Enoki is great, but that accent  wears on me sometimes."},
                {fals, fals, 0,  "MAPLE                            I'm starting to hear a little    Quebec in Aaron's voice, too.    It bothers me."},
                {fals, fals, 0,  "MAPLE                            So what are you writing?"},
                {fals, fals, 0,  "RUFUS                            ...                              You're going to think it's       dumb. It's a drawing."},
                {fals, fals, 0,  "MAPLE                            Look, I just sold everything I   owned to move to this stupid     island, your drawing isn't dumb."},  
                {fals, fals, 0,  "RUFUS                            ...Okay, it's a frog. I saw this picture of a frog when I was a   kid, and I don't know why, but itmakes me nostalgic."},
                {fals, fals, 0,  "RUFUS                            I can't quite remember what it   looked like though, so I keep    trying. I don't know why but it'ssomething I just have to do."},  
                {fals, fals, 0,  "MAPLE                            Yeah, that is pretty dumb, but   I think I get what you mean."},
                {fals, fals, 0,  "MAPLE                            Hey, I know it's not my place to offer, but you got a place to    sleep? I know it's cold out, but we have a bathtub."},
                {fals, fals, 0,  "RUFUS                            Oh it's fine, I'll be gone in themorning, I don't really want to  interact with anyone else. You   seem reasonable, though."},
                {fals, fals, 0,  "MAPLE                            You too. It was kind of nice to  find someone with any sense to   chat for a little while."},
                {fals, fals, 0,  "S04:07"},
                {fals, fals, 0,  "BG: fadeout"},
                {fals, fals, 0,  "MAPLE                            You take care of yourself,       alright? Ravi de vous rencontrer,Rufus."},
                {fals, fals, 0,  "RUFUS                            You too! Ravi de vous rencontrer,Maple."},
                {fals, fals, 0, "COM: Endscene"}
            };
            dialogue_page(lc);
            return 0;
            break;
        }
        
        default: {
            return 1;
            break;
        }
    }
}