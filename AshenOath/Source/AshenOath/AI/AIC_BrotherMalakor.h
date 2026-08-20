// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_BrotherMalakor.generated.h"

UENUM(BlueprintType)
enum class EAshenBossPhase : uint8
{
	Phase1_Zealot,
	Phase2_ScriptureBlade,
	Phase3_MartyrAvenger
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBrotherMalakorPhaseTransition, EAshenBossPhase, NewPhase);

/**
 * AAIC_BrotherMalakor
 * 3-Phase Inquisitorial Boss AI Controller dynamically shifting agro between Kaelen and companions.
 */
UCLASS()
class ASHENOATH_API AAIC_BrotherMalakor : public AAIController
{
	GENERATED_BODY()
public:
	AAIC_BrotherMalakor();
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Boss AI")
	FOnBrotherMalakorPhaseTransition OnMalakorPhaseTransition;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss AI")
	EAshenBossPhase CurrentBossPhase = EAshenBossPhase::Phase1_Zealot;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss AI")
	void EvaluatePhaseProgression(float CurrentHealthPercent);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss AI")
	void ShiftAgroTarget(AActor* PriorityTarget);
};
