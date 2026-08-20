// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPsychicEchoPhasedPhaseController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBossPhaseTransition, int32, NewPhase);

/**
 * UAshenPsychicEchoPhasedPhaseController
 * Controller orchestrating 3 combat phases for inner phantom encounters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychicEchoPhasedPhaseController : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPsychicEchoPhasedPhaseController();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | AI")
	FOnBossPhaseTransition OnPhaseTransition;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	int32 CurrentPhase = 1;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void EvaluatePhaseTransition(float BossHealthPercent);
};
