// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenUserWidget_SoulConstellation.h"
#include "AshenSoulConstellationSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UAshenUserWidget_SoulConstellation::NativeConstruct()
{
	Super::NativeConstruct();
	RefreshConstellationTree();
}

void UAshenUserWidget_SoulConstellation::RegisterStarNode(UAshenUserWidget_ConstellationNode* StarNode)
{
	if (StarNode && !StarNodes.Contains(StarNode))
	{
		StarNodes.Add(StarNode);
		StarNode->OnNodeUnlocked.AddDynamic(this, &UAshenUserWidget_SoulConstellation::HandleNodeUnlocked);
	}
}

void UAshenUserWidget_SoulConstellation::RefreshConstellationTree()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			CurrentStateVector = Kernel->GetStateVector();
			UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SoulConstellation: Refreshed State Vector — Resolve: %.2f | Debt: %.2f | Isolation: %.2f"),
				CurrentStateVector.Resolve, CurrentStateVector.IntegrationDebt, CurrentStateVector.Isolation);
		}
	}

	for (UAshenUserWidget_ConstellationNode* Node : StarNodes)
	{
		if (Node)
		{
			Node->OnNodeStateUpdated(Node->bIsUnlocked, Node->bCanUnlock);
		}
	}
}

void UAshenUserWidget_SoulConstellation::HandleNodeUnlocked(FName NodeId)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_SoulConstellation: Node '%s' unlocked in UI tree!"), *NodeId.ToString());
	RefreshConstellationTree();
}
