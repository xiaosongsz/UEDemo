CleverCreator = {}

--Core
require('CleverCreator/Core/Global')
require('CleverCreator/Core/Class')
require('CleverCreator/Core/UClass')

--Scene
local SceneManager_Class = require('CleverCreator/Scene/SceneManager')
--UI
local UIManager_Class = require('CleverCreator/UI/UIManager')

function CleverCreator_Init(Instance)
    GameInstance = Instance
    print('CleverCreator_Init', Instance)
    --SceneManager
    SceneManager = SceneManager_Class(Instance:GetSceneManager())
    -- SceneManager:init()
    -- SceneManager:doUClass()

    --UIManager
    UIManager = UIManager_Class(Instance:GetUIManager())
    -- UIManager:init()
    -- UIManager:doUClass()
end