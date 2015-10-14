#ifndef __CoCosAudioManager_h_
#define __CoCosAudioManager_h_

#include "GameDef.h"
#include "Singleton.h"

class CoCosAudioManager : public Singleton_Auto<CoCosAudioManager>
{
public:
	CoCosAudioManager();
	~CoCosAudioManager();

	void				SetMusicEnable(bool enable);
	void				SetEffectEnable(bool enable);

	/* Name		��PlayMusic
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ���ű�������,֧�ָ�ʽ����:Android(MP3��WAV��3GP),iOS(MP3��CAF),Win32(MID��WAV)
	 * Param	: path ����·�� loop �Ƿ�ѭ��
	 * Return	: none
	 */
	void PlayMusic(std::string path, bool loop);

	/* Name		��PlayEffect
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ������Ч,֧�ָ�ʽ Android(OGG,WAV),iOS(CAF),Win32(MID��WAV)
	 * Param	: id ����id
	 * Return	: none
	 */
	void PlayEffect(int id);

	/* Name		��SetMusicVolume
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ���ñ����������� 
	 * Param	: volume ���� ֵ��Χ 0.0-1.0
	 * Return	: none
	 */
	void SetMusicVolume(float volume);

	/* Name		��SetEffectVolume
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ������Ч����
	 * Param	: volume ���� ֵ��Χ 0.0-1.0
	 * Return	: none
	 */
	void SetEffectVolume(float volume);

	/* Name		��PauseAll
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ��ͣ
	 * Param	: none
	 * Return	: none
	 */
	void PauseAll();

	/* Name		��ResumeAll
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: �ָ�
	 * Param	: none
	 * Return	: none
	 */
	void ResumeAll();

	/* Name		��ClearAudioData
	 * Author	��PengLongHua
	 * Date		: 2015-07-13
	 * Desc		: ���������Ч����
	 * Param	: none
	 * Return	: none
	 */
	void ClearAudioData();

private:
	bool			m_bMusicEnable;
	bool			m_bEffectEnable;
};

#define gCocosAudio CoCosAudioManager::Instance()

#endif //__CoCosAudioManager_h_