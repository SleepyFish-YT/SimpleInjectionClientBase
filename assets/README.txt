if you want to add custom fonts or images add them to this folder.

how to add a font properly:
 1. download the font (.ttf format only)
 2. download ImHex and open it (https://github.com/WerWolv/ImHex/releases/latest)
 3. drag your font file into im hex
 4. ImHex now should load that font in hex editor
 5. select all (ctrl + a), right click with mouse and click "copy as" and choose "c array"ä
 6. you can now close ImHex
 7. create a new file in "assets/fonts" called "your_font_name.h" (header file only) and paste the code there
 8. it might look like this now: "const uint8_t data[208204] = {" change it to "unsigned char your_font_name[208204] = {"
 9. go in method: "Interface::setupImgui" and after "io.Fonts->AddFontDefault();" add this:
10. Interface::fonts["your_font_name_your_font_size"] io.Fonts->AddFontFromMemoryTTF(your_font_name, sizeof(your_font_name), your_font_size);
11. you now can use it like this:

    example: if my font is called rubiks and i want to use it with size 20 i would do this:
    Interface::fonts["rubiks_20"] io.Fonts->AddFontFromMemoryTTF(rubiks, sizeof(rubiks), 20.0f);

    and i would use it like this:

    ImGui::PushFont(Interface::fonts["rubiks_20"]);
        ImGui::Text("your text with your custom added font");
    ImGui::PopFont();

==========================================================================================================================================

how to add an image properly:
 1. download the image (.png format only)
 2. download ImHex and open it (https://github.com/WerWolv/ImHex/releases/latest)
 3. drag your image file into im hex
 4. ImHex now should load that image in hex editor
 5. select all (ctrl + a), right click with mouse and click "copy as" and choose "c array"
 6. you can now close ImHex
 7. create a new file in "assets/images" called "your_image_name.h" (header file only) and paste the code there
 8. it might look like this now: "const uint8_t data[208204] = {" change it to "const unsigned char your_image_name[208204] = {"
 9. download stb_image and add it in "/libraries" folder
10. go in method: "Interface::setupImgui" and after all the font adding stuff add this:
11. Interface::images["your_image_name"] stbi_load_from_memory(your_image_name, &your_image_width, &your_image_height, &your_image_channels, 4);
12. you now can use it like this:

ImGui::Image(Interface::images["your_image_name"], ImVec2(your_image_width, your_image_height));

to navigate the image use: ImGui::SetOffset({x, y});