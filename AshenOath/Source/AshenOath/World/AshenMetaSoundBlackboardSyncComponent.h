// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenMetaSoundBlackboardSyncComponent.generated.h"

/**
 * UAshenMetaSoundBlackboardSyncComponent
 * Pushes FSoulStateVector floats directly to MetaSound blackboards.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMetaSoundBlackboardSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMetaSoundBlackboardSyncComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);
};
