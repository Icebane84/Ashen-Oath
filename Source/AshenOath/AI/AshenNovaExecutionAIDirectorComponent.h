// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNovaExecutionAIDirectorComponent.generated.h"

/**
 * UAshenNovaExecutionAIDirectorComponent
 * AI Director managing enemy stagger susceptibility and cinematic crowd freeze during Nova finisher execution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaExecutionAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaExecutionAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void EnforceFinisherStaggerState(bool bIsFinisherActive, float StaggerDuration);
};
