--CleverCreator
require("CleverCreator/Header")

print('Hello sLua')

print("----------------------------------------")

function BeginPlay()
    print("BeginPlay")
    local demo = UIManager:OpenWidget("Demo", "")
    -- UIManager:OpenGroup("Loading")
    print(demo)
    print(UIManager)
end