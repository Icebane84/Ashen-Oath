// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 418: AshenOath_ThreatPerceptionComponent

#include "AshenOath_ThreatPerceptionComponent.h"
#include "UAICognitiveComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

UAshenOath_ThreatPerceptionComponent::UAshenOath_ThreatPerceptionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.25f;
}

void UAshenOath_ThreatPerceptionComponent::BeginPlay()
{
	Super::BeginPlay();

	const AAIController* AIController = Cast<AAIController>(GetOwner());
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenOath_ThreatPerceptionComponent must be owned by an AAIController"));
		return;
	}

	PerceptionComp = AIController->FindComponentByClass<UAIPerceptionComponent>();
	if (UAIPerceptionComponent* Perception = PerceptionComp.Get())
	{
		Perception->OnTargetPerceptionUpdated.AddDynamic(this, &UAshenOath_ThreatPerceptionComponent::HandlePerceptionUpdated);
	}

	if (const APawn* Pawn = AIController->GetPawn())
	{
		CognitiveComp = Pawn->FindComponentByClass<UAICognitiveComponent>();
	}
}

void UAshenOath_ThreatPerceptionComponent::HandlePerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
}

void UAshenOath_ThreatPerceptionComponent::NotifyDamageReceived(APawn* Instigator, float DamageAmount)
{
	if (!Instigator || DamageAmount <= 0.0f) return;
	const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	DamageAggroLog.Add(TWeakObjectPtr<APawn>(Instigator), Now);
}

void UAshenOath_ThreatPerceptionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	RecomputeThreatTable();
}

float UAshenOath_ThreatPerceptionComponent::ScoreCandidate(const APawn* Candidate, float LastSeenAge) const
{
	if (!Candidate) return 0.0f;

	const AActor* SelfOwner = GetOwner();
	const AAIController* SelfController = SelfOwner ? Cast<AAIController>(SelfOwner) : nullptr;
	const APawn* SelfPawn = SelfController ? SelfController->GetPawn() : nullptr;
	if (!SelfPawn) return 0.0f;

	const float Distance = FVector::Dist(SelfPawn->GetActorLocation(), Candidate->GetActorLocation());
	if (Distance > ScoringParams.MaxEngagementRange) return 0.0f;

	const float DistanceScore = ScoringParams.DistanceWeight * (1.0f - (Distance / ScoringParams.MaxEngagementRange));
	const float RecencyScore = FMath::Exp(-LastSeenAge);

	float DamageScore = 0.0f;
	if (const float* LastHitTime = DamageAggroLog.Find(TWeakObjectPtr<APawn>(const_cast<APawn*>(Candidate))))
	{
		const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
		const float Age = Now - *LastHitTime;
		DamageScore = ScoringParams.DamageAggroWeight * FMath::Pow(0.5f, Age / ScoringParams.DamageAggroHalfLifeSeconds);
	}

	return DistanceScore + RecencyScore + DamageScore;
}

void UAshenOath_ThreatPerceptionComponent::RecomputeThreatTable()
{
	UAIPerceptionComponent* Perception = PerceptionComp.Get();
	UAICognitiveComponent* Cognitive = CognitiveComp.Get();
	if (!Perception || !Cognitive) return;

	TArray<AActor*> PerceivedActors;
	Perception->GetKnownPerceivedActors(nullptr, PerceivedActors);

	TArray<FAshenThreatEntry> NewEntries;
	NewEntries.Reserve(PerceivedActors.Num());

	for (AActor* Actor : PerceivedActors)
	{
		APawn* CandidatePawn = Cast<APawn>(Actor);
		if (!CandidatePawn) continue;

		FActorPerceptionBlueprintInfo Info;
		Perception->GetActorsPerception(Actor, Info);

		float BestAge = TNumericLimits<float>::Max();
		for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
		{
			if (Stimulus.WasSuccessfullySensed())
			{
				BestAge = FMath::Min(BestAge, Stimulus.GetAge());
			}
		}

		if (BestAge < TNumericLimits<float>::Max())
		{
			float Score = ScoreCandidate(CandidatePawn, BestAge);
			if (Score > 0.0f)
			{
				FAshenThreatEntry Entry;
				Entry.ThreatTarget = CandidatePawn;
				Entry.ThreatScore = Score;
				NewEntries.Add(Entry);
			}
		}
	}

	Cognitive->UpdateThreatTable(NewEntries);
}
