﻿//---------------------------------------------------------------
// File: SceneManager.h
// Proj: HycFrame2D
// Info: シーン管理する機能の対応
// Date: 2021.06.09
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#pragma once

#include <array>
#include <string>

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    bool StartUp();

    void PostStartUp(class PropertyManager* _pmPtr,
        class ObjectFactory* _ofPtr);

    void CleanAndStop();

    void SetShouldTurnOff(bool _value);

    bool GetShoudTurnOff() const;

    void UpdateSceneManager(float _deltatime);

    void LoadSceneNode(std::string _name, std::string _path);

    class PropertyManager* GetPropertyManager() const;

    class ObjectFactory* GetObjectFactory() const;

    unsigned int GetNeedToLoad() const;

    unsigned int GetHasLoaded() const;

    void PlusHasLoaded();

    bool GetLoadFinishedFlag() const;

    void SetLoadFinishedFlag(bool _value);

private:
    void LoadLoadingScene();

    void ReleaseLoadingScene();

    void LoadNextScene();

private:
    class PropertyManager* mPropertyManagerPtr;

    class ObjectFactory* mObjectFactoryPtr;

    bool mShouldTurnOff;

    class SceneNode* mLoadingScenePtr;

    class SceneNode* mCurrentScenePtr;

    class SceneNode* mNextScenePtr;

    class SceneNode* mReleaseScenePtr;

    bool mLoadSceneFlg;

    std::array<std::string, 2> mLoadSceneInfo;

    std::array<class SceneNode*, 2> mScenePool;

    unsigned int mNeedToLoadSize;

    unsigned int mHasLoadedSize;

    bool mLoadFinishFlg;
};

