#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <iomanip>
#include <array>
#include <vector>

#include "include/GuitarTab.h"

#define DEFAULT_VALUE 10000

inline static std::string operator""_str(const char* str, size_t len)
{
	return std::string(str);
}

void GuitarTab::addNote(GuitarTab::Stave& activeStave, uint32_t idx, const Note& note)
{
	if (activeStave[0].size() <= idx)
		for(auto& string : activeStave)
			string.emplace_back(GuitarTab::Note{SPACE});
	if (note.stringTuning == GuitarTab::StringName::INVALID)
		activeStave[(size_t)tab.lastString].back() = note;
	else
		activeStave[(size_t)note.stringTuning].back() = note;
}

void GuitarTab::addNote(GuitarTab::Stave& activeStave, uint32_t idx,  uint32_t stringNumber, uint32_t value)
{
	if (activeStave[0].size() <= idx)
		for(auto& string : activeStave)
			string.emplace_back(GuitarTab::Note{SPACE});
	activeStave[stringNumber].back() = GuitarTab::Note((GuitarTab::StringName)stringNumber, value, false);
}

size_t GuitarTab::currentStringsIdx()
{
	auto& activeStave = tab.staves.back();
	return activeStave[0].size();
}


GuitarTab& GuitarTab::BeginGuitarTab(uint32_t spacing)
{
	tab = {};
	tab.spacing = spacing + 1;
	tab.staves.push_back(GuitarTab::Stave{});
	return *this;
}

GuitarTab& GuitarTab::AddKey(std::string key)
{
	tab.key = key;
	return *this;
}

GuitarTab& GuitarTab::AddTimeSignature(uint32_t bpm, uint32_t beatnote)
{
	tab.ts = GuitarTab::TimeSignature{bpm, beatnote};
	return *this;
}


GuitarTab& GuitarTab::NextString(uint32_t jump)
{
	tab.lastString += jump;
	tab.lastString %= 6;
	return *this;
}

GuitarTab& GuitarTab::PrevString(uint32_t jump)
{
	tab.lastString -= jump;
	tab.lastString %= 6;
	return *this;
}

GuitarTab& GuitarTab::SetString(GuitarTab::StringName string)
{
	tab.lastString = (size_t)string;
	return *this;
}

GuitarTab& GuitarTab::AddStave()
{
	tab.staves.emplace_back(GuitarTab::Stave{});
	return *this;
}

GuitarTab& GuitarTab::AddNote(std::initializer_list<GuitarTab::Note> notes)
{
	auto& activeStave = tab.staves.back();
	for (auto& note : notes)
	{
		addNote(activeStave, currentStringsIdx(), note);
		if (note.isHarmonic)
			if (tab.spacing < 3)
				tab.spacing = 3;
	}

	if (notes.end()->stringTuning != INVALID)
		tab.lastString = (size_t)notes.end()->stringTuning;

	return *this;
}

GuitarTab& GuitarTab::AddNote(std::initializer_list<uint32_t> note_values)
{
	auto& activeStave = tab.staves.back();
	for (auto& note : note_values)
	{
		addNote(activeStave, currentStringsIdx(), tab.lastString, note);
	}
	return *this;
}

GuitarTab& GuitarTab::AddSpace(uint32_t count)
{
	auto& activeStave = tab.staves.back();
	for(int i =0; i < count; i++)
	{
		size_t idx = currentStringsIdx();
		for (auto& string : activeStave)
			addNote(activeStave, idx, GuitarTab::Note(SPACE));
	}
	return *this;
}

GuitarTab& GuitarTab::AddPullUp(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(PULL_UP, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddHammerOn(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(HAMMER_ON, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddRelease(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(RELEASE, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddSlideUp(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(SLIDE_UP, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddSlideUp(uint32_t start, uint32_t end, uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;
	auto& activeStave = tab.staves.back();
	AddNote({start});
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(SLIDE_UP, GuitarTab::StringName(stringNumber)));
	AddNote({end});

	return *this;
}

GuitarTab& GuitarTab::AddSlideDown(uint32_t start, uint32_t end, uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;
	auto& activeStave = tab.staves.back();
	AddNote({start});
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(SLIDE_DOWN, GuitarTab::StringName(stringNumber)));
	AddNote({end});

	return *this;
}

GuitarTab& GuitarTab::AddSlideDown(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(SLIDE_DOWN, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddBend(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(BEND, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddVibrato(uint32_t stringNumber)
{
	if (stringNumber == DEFAULT_VALUE)
		stringNumber = tab.lastString;
	else
		tab.lastString = stringNumber;

	auto& activeStave = tab.staves.back();
	addNote(activeStave, currentStringsIdx(), GuitarTab::Note(VIBRATO, GuitarTab::StringName(stringNumber)));

	return *this;
}

GuitarTab& GuitarTab::AddBarLine()
{
	auto& activeStave = tab.staves.back();
	size_t idx = currentStringsIdx();
	for (size_t i = 0; i < 6; i++)
		addNote(activeStave, idx, GuitarTab::Note(BARLINE, StringName(i)));

	return *this;
}

GuitarTab& GuitarTab::BeginRepeatBarLine()
{
	auto& activeStave = tab.staves.back();
	size_t idx = currentStringsIdx();
	for (size_t i = 0; i < 6; i++)
		addNote(activeStave, idx, GuitarTab::Note(BEGIN_REPEAT_BARLINE, StringName(i)));

	return *this;
}

GuitarTab& GuitarTab::EndRepeatBarLine()
{
	auto& activeStave = tab.staves.back();
	size_t idx = currentStringsIdx();
	for (size_t i = 0; i < 6; i++)
		addNote(activeStave, idx, GuitarTab::Note(END_REPEAT_BARLINE, StringName(i)));

	return *this;
}

GuitarTab& GuitarTab::AddMeasureRepeat()
{
	auto& activeStave = tab.staves.back();
	size_t idx = currentStringsIdx();
	for (size_t i = 0; i < 6; i++)
		addNote(activeStave, idx, GuitarTab::Note(MEASURE_REPEAT, StringName(i)));

	return *this;
}

GuitarTab& GuitarTab::AddChordOrInterval(std::initializer_list<std::pair<uint32_t, uint32_t>> intervals)
{
	auto& activeStave = tab.staves.back();
	uint32_t idx = currentStringsIdx();
	for (auto& [string, value] : intervals)
		addNote(activeStave, idx, string, value);

	return *this;
}

GuitarTab& GuitarTab::EndGuitarTab()
{
	if ((int)fileOutput.tellg() != (int)fileOutput.beg)
		Separator();
	Header("Guitar Tab", 2);
	Body(("Key: "_str + tab.key + "\n"_str).c_str());
	Body(("Time Signature: "_str + std::to_string(tab.ts.bpm) + "/"_str + std::to_string(tab.ts.beatNote)).c_str());

	fileOutput << "```verbose\n";

	auto printWithPadding = [&](std::string txt, uint32_t padding){
		fileOutput << std::setfill('-') << std::setw(padding) << txt;
	};

	auto printWithoutPadding = [&](std::string txt){
		fileOutput << txt;
	};

	constexpr static char stringNames[] = {'E', 'A', 'D', 'G', 'B', 'e'};

	for (auto& stave : tab.staves)
	{
		for (int i = 5; i >= 0; i--)
		{
			fileOutput << stringNames[i] << "|";
			auto& string = stave[i];
			for (size_t idx = 0; idx < string.size(); idx++)
			{
				auto& note = string[idx];
				switch(note.type)
				{
				case NoteType::SPACE:
					printWithPadding("-", this->tab.spacing);
				break;
				case NoteType::TAB:
					if (!note.isHarmonic)
						printWithPadding(std::to_string(note.number), this->tab.spacing);
					else
						printWithPadding("<"_str + std::to_string(note.number) + ">"_str, this->tab.spacing);
				break;
				case NoteType::PULL_UP:
					fileOutput << 'p';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::HAMMER_ON:
					fileOutput << 'h';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::VIBRATO:
					fileOutput << 'V';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::RELEASE:
					fileOutput << 'R';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::BEND:
					fileOutput << 'B';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::SLIDE_UP:
					fileOutput << '/';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::SLIDE_DOWN:
					fileOutput << '\\';
					printWithoutPadding(std::to_string(string[idx+1].number));
					printWithPadding("", tab.spacing * 1.5);
					idx++;
				break;
				case NoteType::BARLINE:
					printWithPadding("|", this->tab.spacing);
				break;
				case NoteType::BEGIN_REPEAT_BARLINE:
					fileOutput << "|:";
				break;
				case NoteType::END_REPEAT_BARLINE:
					fileOutput << ":|";
				break;
				case NoteType::MEASURE_REPEAT:
					printWithPadding("%", this->tab.spacing);
				break;
				}
			}
			// printWithPadding(" ", this->tab.spacing);
			fileOutput << "\n";
		}
		fileOutput << "\n";
	}

	fileOutput << "```";
	tab = {};
	return *this;
}