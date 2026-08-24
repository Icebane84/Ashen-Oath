// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenUserWidget_TripartiteAttunementHUD.generated.h"

/**
 * UAshenUserWidget_TripartiteAttunementHUD
 * 
 * UMG widget visualizing the 3-node attunement triangle, active silence contract, and finisher readiness.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TripartiteAttunementHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_TripartiteAttunementHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the tripartite HUD displays */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Tripartite")
	void UpdateTripartiteHUD(
		ETripartiteBehaviorMode Mode,
		ECompanionAttunementPhase Phase,
		float AttunementScore,
		float GarrettFlankAngle,
		float SerafinaDist);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tripartite")
	ETripartiteBehaviorMode DisplayedMode = ETripartiteBehaviorMode::CombatEngagement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tripartite")
	ECompanionAttunementPhase DisplayedPhase = ECompanionAttunementPhase::GuardedAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tripartite")
	float DisplayedAttunementScore = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tripartite")
	float DisplayedFlankAngle = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tripartite")
	float DisplayedSerafinaDistance = 450.0f;
};
