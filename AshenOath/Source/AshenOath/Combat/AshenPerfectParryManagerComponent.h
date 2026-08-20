// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPerfectParryManagerComponent.generated.h"

/**
 * UAshenPerfectParryManagerComponent
 * Manages precision parry timing window (0.20s), Sanity restoration on successful parry, and time-dilation trigger events.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPerfectParryManagerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPerfectParryManagerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float PerfectParryWindowDuration = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float SanityRestoredOnParry = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool EvaluateParryTiming(float TimeSinceGuardInitiated, float& OutSanityRestored);
};
