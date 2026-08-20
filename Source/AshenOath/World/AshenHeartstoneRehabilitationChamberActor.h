// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenHeartstoneRehabilitationChamberActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChamberRitualCompleted, float, PurifiedTraitScore);

/**
 * AAshenHeartstoneRehabilitationChamberActor
 * Physical Mindscape chamber actor performing deep identity synthesis rituals.
 */
UCLASS()
class ASHENOATH_API AAshenHeartstoneRehabilitationChamberActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenHeartstoneRehabilitationChamberActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | World")
	FOnChamberRitualCompleted OnRitualCompleted;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bRitualInProcess = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool BeginIdentitySynthesisRitual();
};
