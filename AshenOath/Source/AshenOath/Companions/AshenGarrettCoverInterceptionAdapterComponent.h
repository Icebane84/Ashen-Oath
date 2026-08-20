// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGarrettCoverInterceptionAdapterComponent.generated.h"

/**
 * UAshenGarrettCoverInterceptionAdapterComponent
 * Binds Garrett's companion interception decision logic to GarrettTrust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettCoverInterceptionAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettCoverInterceptionAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetInterceptionThreshold() const { return InterceptionThreshold; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float InterceptionThreshold = 0.5f;
};
