#pragma once

#include <String>

class SpriteSheet;
using Frame = unsigned int;

class Anim_Base 
{
	friend class SpriteSheet;
public:
	Anim_Base();
	virtual ~Anim_Base();
	
	void SetSpriteSheet(SpriteSheet* l_sheet);
	void SetFrame(const unsigned int& l_frame);
	void SetLooping(const bool l_loop);
	void SetName(const std::string l_name);

	std::string GetName() { return m_name; };

	bool IsInAction();
	bool IsPlaying() { return m_playing; };

	void Play();
	void Pause();
	void Stop();
	void Reset();
	virtual void Update(const float& l_dT);
	friend std::stringstream& operator >> (std::stringstream& l_stream, Anim_Base& a)
	{
		a.ReadIn(l_stream);
		return l_stream;
	}
protected:
	virtual void FrameStep() = 0;
	virtual void CropSprite() = 0;
	virtual void ReadIn(std::stringstream& l_stream) = 0;

	Frame m_frameCurrent;
	Frame m_frameStart;
	Frame m_frameEnd;
	Frame m_frameRow;
	int m_frameActionStart; // Frame when a specific "action" begins
	int m_frameActionEnd; // Frame when a specific "action" ends
	float m_frameTime;
	float m_elapsedTime;
	bool m_loop;
	bool m_playing;
	std::string m_name;
	SpriteSheet* m_spriteSheet;
};
