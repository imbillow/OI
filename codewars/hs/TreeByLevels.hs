module TreeByLevels where

data TreeNode a = TreeNode
  { left :: Maybe (TreeNode a),
    right :: Maybe (TreeNode a),
    value :: a
  }
  deriving (Show)

treeByLevels :: Maybe (TreeNode a) -> [a]
treeByLevels Nothing = []
treeByLevels (Just (TreeNode left right value)) = value : head left ++ head right ++ children left ++ children right
  where
    head Nothing = []
    head (Just (TreeNode _ _ x)) = [x]
    children Nothing = []
    children (Just (TreeNode l r _)) = treeByLevels l ++ treeByLevels r

tree =
  Just
    ( TreeNode
        { left =
            Just
              ( TreeNode
                  { left =
                      Just
                        ( TreeNode
                            { left =
                                Just
                                  ( TreeNode
                                      { left = Nothing,
                                        right = Nothing,
                                        value =
                                          -10
                                      }
                                  ),
                              right = Just (TreeNode {left = Nothing, right = Nothing, value = -9}),
                              value = -10
                            }
                        ),
                    right = Just (TreeNode {left = Just (TreeNode {left = Nothing, right = Nothing, value = 7}), right = Nothing, value = 5}),
                    value = 4
                  }
              ),
          right = Just (TreeNode {left = Just (TreeNode {left = Nothing, right = Nothing, value = 9}), right = Just (TreeNode {left = Nothing, right = Nothing, value = 7}), value = 3}),
          value = 2
        }
    )
