// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenWhiteFlameAIDirectorComponent.generated.h"

/**
 * UAshenWhiteFlameAIDirectorComponent
 * AI Director orchestrating companion behavior during the 12.0s White Flame state (Garrett perimeter lockdown, Serafina radiant anchoring).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void SynchronizeCatharsisAI(bool bIsWhiteFlameActive);
};
