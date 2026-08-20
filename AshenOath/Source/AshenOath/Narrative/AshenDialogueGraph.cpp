// AshenDialogueGraph.cpp
// Copyright Ashen Oath. All rights reserved.

#include "AshenDialogueGraph.h"

const FDialogueNodeRecord* UAshenDialogueGraph::FindNode(FName NodeID) const
{
	for (const FDialogueNodeRecord& Node : Nodes)
	{
		if (Node.NodeID == NodeID)
		{
			return &Node;
		}
	}
	return nullptr;
}
