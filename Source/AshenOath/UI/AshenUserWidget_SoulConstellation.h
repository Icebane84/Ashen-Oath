// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulStateVector.h"
#include "AshenUserWidget_ConstellationNode.h"
#include "AshenUserWidget_SoulConstellation.generated.h"

class UAshenSoulConstellationSubsystem;

/**
 * UAshenUserWidget_SoulConstellation
 *
 * Master UI lens container for the Soul Constellation identity tree.
 * Displays real-time SoulStateVector metrics (Coherence, Debt, Isolation),
 * manages array of registered star nodes, and orchestrates node unlocking.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulConstellation : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	void RefreshConstellationTree();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	void RegisterStarNode(UAshenUserWidget_ConstellationNode* StarNode);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Constellation")
	float GetCurrentResolve() const { return CurrentStateVector.Resolve; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Constellation")
	float GetCurrentIntegrationDebt() const { return CurrentStateVector.IntegrationDebt; }

	// --- Registered Nodes ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Constellation")
	TArray<TObjectPtr<UAshenUserWidget_ConstellationNode>> StarNodes;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Constellation")
	FSoulStateVector CurrentStateVector;

	UFUNCTION()
	void HandleNodeUnlocked(FName NodeId);
};
