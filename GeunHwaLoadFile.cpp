#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::GeunHwaImage()
{
	_loading->loadImage("�κ�����", "resource/��Ʈ�ξ�/�κ�� ���.bmp", 1280, 720);
	_loading->loadImage("�κ���ΰ�", "resource/��Ʈ�ξ�/�κ�� �ΰ�.bmp", 650, 274, true, MAGENTA);
	_loading->loadImage("�κ����ư", "resource/��Ʈ�ξ�/�κ�� ��ư.bmp", 130, 105, true, MAGENTA);
	_loading->loadImage("�κ����ѱ�", "resource/��Ʈ�ξ�/�κ�� ��ѱ�.bmp", 217, 228, true, MAGENTA);
	_loading->loadImage("�κ������", "resource/��Ʈ�ξ�/�κ�� ����.bmp", 400, 545, true, MAGENTA);
	_loading->loadImage("��ŸƮ�����", "resource/��Ʈ�ξ�/��ŸƮ�����.bmp", 1280, 720);
	_loading->loadImage("��ŸƮ������â", "resource/��Ʈ�ξ�/��ŸƮ�� ����.bmp", 546, 299);
	_loading->loadImage("��ŸƮ�������ڽ�", "resource/��Ʈ�ξ�/��ŸƮ�� �����ڽ�.bmp", 480, 106, true, MAGENTA);



}


void loadingScene::GeunHwaSound()
{
	_loading->loadSound("�κ���������", "resource/����/�κ���������.wav", true, true);
	// ��ŸƮ�� ����
	_loading->loadSound("��������", "resource/����/���� ����.wav");
	_loading->loadSound("�����̵�����", "resource/����/���� �̵� ����.wav");

}

