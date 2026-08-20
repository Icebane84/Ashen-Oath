// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenIdentityCompilerComponent.generated.h"

/**
 * UAshenIdentityCompilerComponent
 * Performs the full CompileIdentity() synthesis pass, converting raw imprint floats and active lens weights into a compiled FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIdentityCompilerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIdentityCompilerComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	FSoulStateVector CompileIdentity(float SanityRatio, float InstabilityScore, float IsolationWeight, float InGarrettTrust, float InSerafinaTrust, EInterpretiveLens ActiveLens);
};
