// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenBehavioralProfileCompiler.generated.h"

/**
 * UAshenBehavioralProfileCompiler
 * Component that compiles raw weight scalars (Stance, Empathic, Tactical) into the FAshenBehavioralProfile semantic firewall layer.
 * Outputs the compiled profile upstream to USoulConstellationSubsystem on demand.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBehavioralProfileCompiler : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBehavioralProfileCompiler();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	FAshenBehavioralProfile CompileProfileFromWeights(float Stance, float Empathic, float Tactical);
};
