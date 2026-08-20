// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPsychicEchoResolverComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPsychicEchoResolved, FName, EchoID, float, HarmonyReward);

/**
 * UAshenPsychicEchoResolverComponent
 * Manages imprint resolution, buffer weight decrement, and Constellation Harmony rewards upon memory battle completion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychicEchoResolverComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPsychicEchoResolverComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Memory")
	FOnPsychicEchoResolved OnPsychicEchoResolved;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	float ResolvePsychicEcho(FName EchoID, float ImprintWeight, bool bVictory);
};
