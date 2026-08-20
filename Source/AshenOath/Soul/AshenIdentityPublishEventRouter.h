// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenIdentityPublishEventRouter.generated.h"

/**
 * UAshenIdentityPublishEventRouter
 * Component routing FOnSoulStateVectorInvalidated pulses to named downstream channels:
 * AnimBP parameters, Material Parameter Collections, AI Blackboard keys, Audio MetaSounds parameters, and Dialogue state tables.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIdentityPublishEventRouter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIdentityPublishEventRouter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void RouteStateVectorToDownstreamChannels(const FSoulStateVector& StateVector);
};
