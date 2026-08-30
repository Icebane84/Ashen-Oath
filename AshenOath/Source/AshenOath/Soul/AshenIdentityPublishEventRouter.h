// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenIdentityPublishEventRouter.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimBPStanceRouted, float, Resolve);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMPCCorruptionRouted, float, Corruption, float, Debt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAITacticalTrustRouted, float, GarrettTrust, float, SerafinaTrust);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAudioMetaSoundsRouted, float, ParasitePressure);

/**
 * UAshenIdentityPublishEventRouter
 * Component routing state commits to named downstream channels:
 * AnimBP parameters, Material Parameter Collections, AI Blackboard keys,
 * Audio MetaSounds parameters, and Dialogue state tables.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIdentityPublishEventRouter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenIdentityPublishEventRouter();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Soul")
	void RouteStateVectorToDownstreamChannels(const FSoulStateVector& StateVector, const FSomaticState& SomaticState);

	UFUNCTION()
	void HandleSoulStateCommitted(const FSoulStateVector& NewState, const FSomaticState& SomaticState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Soul")
	FOnAnimBPStanceRouted OnAnimBPStanceRouted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Soul")
	FOnMPCCorruptionRouted OnMPCCorruptionRouted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Soul")
	FOnAITacticalTrustRouted OnAITacticalTrustRouted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Soul")
	FOnAudioMetaSoundsRouted OnAudioMetaSoundsRouted;
};
