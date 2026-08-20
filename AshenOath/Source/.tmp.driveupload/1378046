// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 681: Ashen Behemoth Knockdown Interception Evaluator

#include "AshenBehemothKnockdownInterceptionEvaluator.h"

bool UAshenBehemothKnockdownInterceptionEvaluator::EvaluateBehemothKnockdownInterception(float IncomingImpulse, float ActiveStamina)
{
	const bool bNegated = (ActiveStamina >= 20.0f) && (IncomingImpulse < 1000.0f);
	const float RemainingPoise = FMath::Clamp(ActiveStamina - (IncomingImpulse * 0.05f), 0.0f, 100.0f);

	OnBehemothKnockdownEvaluated.Broadcast(RemainingPoise, bNegated);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBehemothKnockdownInterceptionEvaluator: BEHEMOTH KNOCKDOWN EVALUATED -> Impulse: %.1f | Stamina: %.1f | Remaining Poise: %.1f | Negated: %s."),
		IncomingImpulse, ActiveStamina, RemainingPoise, bNegated ? TEXT("TRUE") : TEXT("FALSE"));

	return bNegated;
}
