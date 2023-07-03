#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <iomanip>
#include <array>
#include <vector>

#include "MDFile.h"

class GuitarTab : public MDFile
{
	struct TimeSignature
	{
		uint32_t bpm;
		uint32_t beatNote;
	};

	enum NoteType
	{
		SPACE,
		TAB,
		PULL_UP,
		HAMMER_ON,
		VIBRATO,
		RELEASE,
		BEND,
		SLIDE_UP,
		SLIDE_DOWN,
		BARLINE,
		BEGIN_REPEAT_BARLINE,
		END_REPEAT_BARLINE,
		MEASURE_REPEAT,
	};

public:
	enum StringName : uint8_t
	{
		E_String = 0,
		A_String = 1,
		D_String = 2,
		G_String = 3,
		B_String = 4,
		e_String = 5,
		INVALID = 6
	};

	struct Note
	{
		NoteType type;
		StringName stringTuning;
		uint32_t number;
		bool isHarmonic;

		inline Note() = default;
		inline Note(NoteType type, StringName stringName = StringName::E_String) : type(type), stringTuning(stringName) {}
		inline Note(StringName stringTuning, uint32_t number, bool isHarmonic = false) : type(NoteType::TAB), stringTuning(stringTuning), number(number), isHarmonic(isHarmonic) {}
		inline Note(uint32_t number, bool isHarmonic = false) : type(NoteType::TAB), stringTuning(StringName::INVALID), number(number), isHarmonic(isHarmonic) {}
	};

	using Stave = std::array<std::vector<Note>, 6>;

private:
	struct Tab
	{
		std::vector<Stave> staves;
		TimeSignature ts;
		std::string key;
		uint32_t spacing;
		uint32_t lastString;
	};


private:
	void addNote(Stave& activeStave, uint32_t idx, const Note& note);
	void addNote(Stave& activeStave, uint32_t idx, uint32_t stringNumber, uint32_t value);
	size_t currentStringsIdx();
public:


	GuitarTab& BeginGuitarTab(uint32_t spacing = 1);
	GuitarTab& AddKey(std::string key);
	GuitarTab& AddTimeSignature(uint32_t bpm, uint32_t beatnote);
	GuitarTab& NextString(uint32_t jump = 1);
	GuitarTab& PrevString(uint32_t jump = 1);
	GuitarTab& SetString(StringName string);
	GuitarTab& AddStave();
	GuitarTab& AddNote(std::initializer_list<Note> notes);
	GuitarTab& AddNote(std::initializer_list<uint32_t> note_values);
	GuitarTab& AddSpace(uint32_t count = 1);
	GuitarTab& AddPullUp(uint32_t stringNumber = 10000);
	GuitarTab& AddHammerOn(uint32_t stringNumber = 10000);
	GuitarTab& AddRelease(uint32_t stringNumber = 10000);
	GuitarTab& AddSlideUp(uint32_t stringNumber = 10000);
	GuitarTab& AddSlideUp(uint32_t start, uint32_t end, uint32_t stringNumber = 10000);
	GuitarTab& AddSlideDown(uint32_t start, uint32_t end, uint32_t stringNumber = 10000);
	GuitarTab& AddSlideDown(uint32_t stringNumber = 10000);
	GuitarTab& AddBend(uint32_t stringNumber = 10000);
	GuitarTab& AddVibrato(uint32_t stringNumber = 10000);
	GuitarTab& AddBarLine();
	GuitarTab& BeginRepeatBarLine();
	GuitarTab& EndRepeatBarLine();
	GuitarTab& AddMeasureRepeat();
	GuitarTab& AddChordOrInterval(std::initializer_list<std::pair<uint32_t, uint32_t>> intervals);
	GuitarTab& EndGuitarTab();

public:
	Tab tab;
};