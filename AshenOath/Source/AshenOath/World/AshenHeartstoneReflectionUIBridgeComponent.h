// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenHeartstoneReflectionUIBridgeComponent.generated.h"

/**
 * UAshenHeartstoneReflectionUIBridgeComponent
 * Binds FSoulStateVector data to AshenUserWidget_HeartstoneReflection.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHeartstoneReflectionUIBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHeartstoneReflectionUIBridgeComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);
};
