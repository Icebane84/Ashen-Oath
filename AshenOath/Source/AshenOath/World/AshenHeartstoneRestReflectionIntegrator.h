// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenHeartstoneRestReflectionIntegrator.generated.h"

/**
 * UAshenHeartstoneRestReflectionIntegrator
 * Connects Heartstone Campfire rest interaction to Soul Constellation State Publisher.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHeartstoneRestReflectionIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHeartstoneRestReflectionIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Campfire")
	void PublishReflectionState(const FSoulStateVector& Vector);
};
