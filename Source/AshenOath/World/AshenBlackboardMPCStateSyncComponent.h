// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenBlackboardMPCStateSyncComponent.generated.h"

/**
 * UAshenBlackboardMPCStateSyncComponent
 * Pushes FSoulStateVector floats directly to Material Parameter Collections (MPC).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBlackboardMPCStateSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBlackboardMPCStateSyncComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);
};
